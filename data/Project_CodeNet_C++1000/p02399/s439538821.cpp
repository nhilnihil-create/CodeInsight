#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
    double a, b;
    int c, d;

    cin >> a >> b;
    
    c = (int)a / (int)b;
    d = (int)a % (int)b;

    printf("%d %d %.8lf\n",c,d,(double)a/b);
}