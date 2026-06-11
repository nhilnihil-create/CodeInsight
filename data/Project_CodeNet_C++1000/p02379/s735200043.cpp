#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double x = pow(double (x1 - x2), 2);
    double y = pow(double (y1 - y2), 2);
    double dis = sqrt(double (x + y));

    printf("%lf\n", dis);
    return 0;
}
