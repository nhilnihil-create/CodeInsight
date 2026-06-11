#include<bits/stdc++.h>
#define sin60 1.732050807568877/2
#define cos60 1.0/2
using namespace std;
int n;
void kohho(int d,double x1,double y1,double x2,double y2){
  if(d==n){
    printf("%f %f\n",x2,y2);
    return;
  }
  double nx1=(2*x1+x2)/3,ny1=(2*y1+y2)/3,nx2=(x1+2*x2)/3,ny2=(y1+2*y2)/3;
  double dx=nx2-nx1,dy=ny2-ny1;
  double cx=dx*cos60-dy*sin60+nx1,cy=dx*sin60+dy*cos60+ny1;
  kohho(d+1,x1,y1,nx1,ny1);
  kohho(d+1,nx1,ny1,cx,cy);
  kohho(d+1,cx,cy,nx2,ny2);
  kohho(d+1,nx2,ny2,x2,y2);
}
int main(){
  cin>>n;
  cout<<"0 0"<<endl;
  kohho(0,0,0,100,0);
  return 0;
}