#include <cstdio>
#include <cmath>

int n;

void make_koch(double px,double py,double qx,double qy,int t){
  if(t==n) return;
  double sx=(2*px+qx)/3;
  double sy=(2*py+qy)/3;
  double tx=(px+2*qx)/3;
  double ty=(py+2*qy)/3;
  double ux=sx+(tx-sx)/2-(ty-sy)*sqrt(3)/2;
  double uy=sy+(ty-sy)/2+(tx-sx)*sqrt(3)/2;
  make_koch(px,py,sx,sy,t+1);
  printf("%f %f\n",sx,sy);
  make_koch(sx,sy,ux,uy,t+1);
  printf("%f %f\n",ux,uy);
  make_koch(ux,uy,tx,ty,t+1);
  printf("%f %f\n",tx,ty);
  make_koch(tx,ty,qx,qy,t+1);
}
int main(){
  scanf("%d",&n);
  printf("%f %f\n",0.0,0.0);
  make_koch(0.0,0.0,100.0,0,0);
  printf("%f %f\n",100.0,0.0);
}