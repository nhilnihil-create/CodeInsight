#include<bits/stdc++.h>
#define PI 3.141592653589793238
using namespace std;

int main(){
    int a,b;cin>>a>>b;
    int h,m;cin>>h>>m;
     double angle_minute_hand=6*m;
     double angle_hour_hand=30*h + 0.5*m;
     double angle=max(angle_minute_hand,angle_hour_hand)-min(angle_minute_hand,angle_hour_hand);
    if(angle>180){
        angle=360-angle;
    }
    if(angle==180){
        printf("%.10f", (double)a+b);
        return 0;
    }
    if(angle==0){
        printf("%.10f", (double)abs(a-b));
        return 0;
    }
     double dist=sqrt((a*a)+(b*b)-2*a*b*cos(angle*PI/180));
    printf("%.10f",dist);
}
