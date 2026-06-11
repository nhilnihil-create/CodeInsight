#include<iostream>
#include<cstdio>
using namespace std;

double r;
double m,s;

int main(){
    cin >> r;
    m = r * r * 3.14159265358979;
    s = r * 2.0 * 3.14159265358979;
    printf("%.8lf %.8lf", m, s);
    return 0;
}