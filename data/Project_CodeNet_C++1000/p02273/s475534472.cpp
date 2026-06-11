#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
double pi = acos(-1);
void kock(int n,double p1x,double p1y,double p2x,double p2y){
    if(n==0){
        return;
    }
    double r=(60*pi)/180;
    double sx = (2.0*p1x+p2x)/3.0;
    double sy = (2*p1y+p2y)/3.0;
    double tx = (p1x+2.0*p2x)/3.0;
    double ty = (p1y+2.0*p2y)/3.0;
    double ux = (tx-sx)*cos(r)-(ty-sy)*sin(r)+sx;
    double uy = (tx-sx)*sin(r)+(ty-sy)*cos(r)+sy;
    
    kock(n-1,p1x,p1y,sx,sy);
    printf("%.8lf %.8lf\n", sx,sy);
    kock(n-1,sx,sy,ux,uy);
    printf("%.8lf %.8lf\n",ux,uy);
    kock(n-1,ux,uy,tx,ty);
    printf("%.8lf %.8lf\n",tx,ty);
    kock(n-1,tx,ty,p2x,p2y);
}
int main(){
    int n;
    cin>>n;
    double p1x=0.0;
    double p1y=0.0;
    double p2x=100.0;
    double p2y=0.0;
    
    printf("%.8lf %.8lf\n",p1x,p1y);
    kock(n,p1x,p1y,p2x,p2y);
    printf("%.8lf %.8lf",p2x,p2y);
    
    return 0;
}
