#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main(){
    double x1,x2,x3,y1,y2,y3,n;
    double m;
    cin>>x1>>y1>>x2>>y2;
    x3 = (x2-x1)*(x2-x1);
    y3 = (y2-y1)*(y2-y1);
    n = x3+y3;
    m = sqrt(n);
    printf("%.8lf\n", m);
return 0;
}

