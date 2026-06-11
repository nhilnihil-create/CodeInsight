#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    double x1,y1,x2,y2,d;
    cin>>x1>>y1>>x2>>y2;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    printf("%f\n",sqrt(d));
    return 0;
}
