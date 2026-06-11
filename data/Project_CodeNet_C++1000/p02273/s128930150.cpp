#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

void koch(int d,double p1x,double p1y,double p2x,double p2y){
    if(d==0) return;
    double sx,sy,ux,uy,tx,ty;
    sx=(p1x*2+p2x)/3;
    sy=(p1y*2+p2y)/3;
    tx=(p1x+p2x*2)/3;
    ty=(p1y+p2y*2)/3;
    ux=(tx-sx)*cos(PI/3)-(ty-sy)*sin(PI/3)+sx;
    uy=(tx-sx)*sin(PI/3)+(ty-sy)*cos(PI/3)+sy;
    koch(d-1,p1x,p1y,sx,sy);
    printf("%.8lf %.8lf\n",sx,sy);
    koch(d-1,sx,sy,ux,uy);
    printf("%.8lf %.8lf\n",ux,uy);
    koch(d-1,ux,uy,tx,ty);
    printf("%.8lf %.8lf\n",tx,ty);
    koch(d-1,tx,ty,p2x,p2y);
}

int main(){
    int n;
    cin>>n;
    double x=0,y=100;
    printf("%.8lf %.8lf\n",x,x);
    koch(n,x,x,y,x);
    printf("%.8lf %.8lf\n",y,x);
}
