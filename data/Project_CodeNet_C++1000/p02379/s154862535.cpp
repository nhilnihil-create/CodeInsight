#include <iostream>
using namespace std;
#include <cmath>
#include <cstdio>

int main(){
    double x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double T = (x1-x2);
    double W = (y1-y2);
    double d = sqrt(T*T + W*W);
    
    printf("%f\n",d);
    return 0;
}
