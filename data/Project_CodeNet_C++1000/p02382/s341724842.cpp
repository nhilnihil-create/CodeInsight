#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){

  int n,i;
  double D=0,vx[100]={},vy[100]={},v[100]={},max=0;

  cin>>n;
  for(i=0; i<n; i++)cin>>vx[i];
  for(i=0; i<n; i++)cin>>vy[i];
  
  for(i=0; i<n; i++){
    if(vx[i]-vy[i]<0)v[i]=vy[i]-vx[i];
    else v[i]=vx[i]-vy[i];
    D+=v[i];
  }
  
  printf("%.6f\n",D);
  D=0;

  for(i=0; i<n; i++){
    v[i]=(vx[i]-vy[i])*(vx[i]-vy[i]);
    D+=v[i];
  }

  printf("%.6f\n",sqrt(D));
  D=0;

  for(i=0; i<n; i++){
    if(vx[i]-vy[i]<0)v[i]=(vy[i]-vx[i])*(vy[i]-vx[i])*(vy[i]-vx[i]);
    else v[i]=(vx[i]-vy[i])*(vx[i]-vy[i])*(vx[i]-vy[i]);
    D+=v[i];
  }

  printf("%.6f\n",pow(D,1.0/3.0));
  D=0;

  for(i=0; i<n; i++){
    if(vx[i]-vy[i]<0){
      if(max<vy[i]-vx[i])max=vy[i]-vx[i];
    }else if(max<vx[i]-vy[i])max=vx[i]-vy[i];
  }
  
  printf("%.6f\n",max);
  
}