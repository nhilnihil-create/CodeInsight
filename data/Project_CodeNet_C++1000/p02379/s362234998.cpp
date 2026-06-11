#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    double x1,y1,x2,y2,d,e,xd,yd;
    cin >> x1 >> y1 >> x2 >> y2;
    xd = (x1 - x2)*(x1 - x2);
    yd = (y1 - y2)*(y1 - y2);
    e = (xd + yd);
    
    d = sqrt(e);
    
    printf("%5f", d);
    cout <<endl;
    
}
