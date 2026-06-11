#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    double x1,y1,x2,y2,x,y,l;
   
    cin >> x1 >> y1 >> x2 >> y2;
    x = x2 - x1;
    y = y2 - y1;
    l = sqrt((x*x) + (y*y));
    
    printf("%lf\n",l);
    return 0;
    
}
