#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double x1,x2,y1,y2,d;
    cin>>x1>>y1>>x2>>y2;
    d=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
    printf("%lf",d);

    return 0;
}
