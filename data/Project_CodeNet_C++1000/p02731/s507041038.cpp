#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long double l;
    cin >> l;

    long double  x = l/3;
    printf("%.10Lf\n", x*x*x);
    return 0;
}