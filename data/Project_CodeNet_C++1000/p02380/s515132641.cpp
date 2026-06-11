#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
    int a,b,C;
    double c,S,L,h;
    cin >> a >> b >> C;
    h = b*sin(C*M_PI/180);
    S = a*h/2;
    c = sqrt(a*a + b*b - 2*a*b*cos(C*M_PI/180));
    L = a+b+c;
    cout  << fixed << S << endl;
    cout  << fixed << L << endl;
    cout  << fixed << h << endl;
}
