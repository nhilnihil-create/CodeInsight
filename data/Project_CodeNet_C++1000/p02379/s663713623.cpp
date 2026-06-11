#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    double x1,y1,x2,y2;
    double distance;
    cin>>x1>>y1>>x2>>y2;
    distance=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    printf("%1f\n",distance);
    return 0;
}
