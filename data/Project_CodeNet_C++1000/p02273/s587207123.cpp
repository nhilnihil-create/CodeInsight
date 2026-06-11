#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void  dv13(int n,double p1[],double p2[]){
  double s[2]={},u[2]={},t[2]={};
  if(n<=0)return;
  s[0]=(2*p1[0]+p2[0])/3;
  s[1]=(2*p1[1]+p2[1])/3;
  t[0]=(p1[0]+2*p2[0])/3;
  t[1]=(p1[1]+2*p2[1])/3;
  u[0]=(t[0]-s[0])*(0.5)-(t[1]-s[1])/2*(sqrt(3))+s[0];
  u[1]=(t[0]-s[0])/2*(sqrt(3))+(t[1]-s[1])*(0.5)+s[1];
  dv13(n-1,p1,s);
  cout<<s[0]<<" "<<s[1]<<endl;
  dv13(n-1,s,u);
  cout<<u[0]<<" "<<u[1]<<endl;
  dv13(n-1,u,t);
  cout<<t[0]<<" "<<t[1]<<endl;
  dv13(n-1,t,p2);
}
int main(){
  int n;
  cin>>n;
  double p1[2]={0.0,0.0},p2[2]={100.0,0.0};
  cout<<p1[0]<<" "<<p1[1]<<endl;
  dv13(n,p1,p2);
  cout<<p2[0]<<" "<<p2[1]<<endl;

  return 0;
}

