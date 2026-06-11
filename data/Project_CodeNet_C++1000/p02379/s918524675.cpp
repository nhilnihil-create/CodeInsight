#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
    double s,x1,y1,x2,y2,a,b;
    cin >> x1 >> y1 >> x2 >> y2;
    a = pow(x2-x1,2);
    b = pow(y2-y1,2);
    s = sqrt(a+b);
    
    printf("%lf\n",s);
    
    return 0;
}
