#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QProcess p;
    p.setWorkingDirectory("/");
    p.start("/usr/local/pear/bin/drush -h");
    p.waitForFinished(-1);

    QString p_stdout = p.readAllStandardOutput();
    QString p_stderr = p.readAllStandardError();
    qDebug() << p_stdout;
    qDebug() << p_stderr;
    ui->textBrowser->setText(p_stdout);
}
