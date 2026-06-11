#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
 
int main(){
  long n,sum[4]={0},max_;
  int x[100],y[100];
  double D[4];
   
  cin >>n;
  for(int i=0;i<n;i++)cin >>x[i];
  for(int i=0;i<n;i++)cin >>y[i];
   
  for(int i=0;i<n;i++){
    if(x[i]-y[i]!=0) max_=max(x[i]-y[i],y[i]-x[i]);
    else max_=0;
    sum[0]+=max_;   
    sum[1]+=max_*max_;
    sum[2]+=max_*max_*max_;
    sum[3]=max(sum[3],max_);
 
  D[0]=sum[0];
  D[1]=(double)sqrt((double)sum[1]);
  D[2]=(double)pow((double)sum[2],1.0/3.0);
  D[3]=(double)sum[3];}
   
  printf("%.6f\n",D[0]);
  printf("%.6f\n",D[1]);
  printf("%.6f\n",D[2]);
  printf("%.6f\n",D[3]);
 
 return 0;
}