#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x3, y3, a;
    x3 = pow(x1 - x2, 2);
    y3 = pow(y1 - y2, 2);
    a = sqrt(x3 + y3);
    printf("%lf\n", a);
    return 0;
}
