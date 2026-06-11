#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a,b,d,r;
    double x,y,f;
    cin >> a >> b;
    x = a;
    y = b;
    d = a / b;
    r = a % b;
    f = x / y;
    printf("%d %d %.5f\n",d,r,f);
    return 0;
}
