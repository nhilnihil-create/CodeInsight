#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(){

    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    double ans;

    ans = pow( pow((x2-x1),2) + pow((y2-y1),2),(0.5));
    printf("%.4f\n", ans ) ;
    return 0;
}