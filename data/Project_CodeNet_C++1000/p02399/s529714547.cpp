#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int a,b,c,d;
    double e;
    cin >> a >>b;
    c = a/b;
    d = a%b;
    e = double(a)/double(b);
    printf("%d %d %10.6f",c,d,e);
}