#include<iostream>
#include<stdio.h>

using namespace std;

#define PI 3.141592653589

int main(int argc,char* argv[])
{
    double r;
    cin >> r;
    printf("%.8lf %.8lf\n",(double)r*r*PI,(double)2*r*PI);
}