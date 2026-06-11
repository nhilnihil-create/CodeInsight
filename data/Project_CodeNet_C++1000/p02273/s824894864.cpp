#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n;
  
void compute(int depth,double x1,double y1,double x2,double y2){
  double si60 = sqrt(3.0)/2.0;
  double co60 = 0.5;
    
  double sx = (x1+x1+x2)/3.0;
  double sy = (y1+y1+y2)/3.0;
  double tx = (x1+x2+x2)/3.0;
  double ty = (y1+y2+y2)/3.0;
    
  double vx = tx-sx;
  double vy = ty-sy;
    
  double ux = sx + co60*vx - si60*vy;
  double uy = sy + si60*vx + co60*vy;
    
  if(depth>=n)return;
    
  compute(depth+1,x1,y1,sx,sy);
  printf("%.8f %.8f\n",sx,sy);
  compute(depth+1,sx,sy,ux,uy);
  printf("%.8f %.8f\n",ux,uy);
  compute(depth+1,ux,uy,tx,ty);
  printf("%.8f %.8f\n",tx,ty);  
  compute(depth+1,tx,ty,x2,y2);
  
    
}
  
int main(){
  cin>>n;
  printf("%.8f %.8f\n",0.0,0.0);
  compute(0,0.0,0.0,100.0,0.0);
  printf("%.8f %.8f\n",100.0,0.0);
  return 0;
}

