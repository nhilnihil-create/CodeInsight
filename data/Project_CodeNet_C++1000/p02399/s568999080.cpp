#include<stdio.h>
#include<iomanip>
#include<iostream>
using namespace std;
int main(){
  int a,b,d,r;
  double f,a2,b2;
  cin>>a>>b;
  d=a/b;
  r=a%b;
  a2=a*1.0;
  b2=b*1.0;
  f=a2/b2;
  cout<<d<<" "<<r<<" ";
  printf("%5f\n",f);
  return 0;
}