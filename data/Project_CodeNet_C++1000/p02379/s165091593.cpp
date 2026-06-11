#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main(){
  double  x1,x2,y1,y2;
  double ans,sax,say; 
  cin>>x1>>y1>>x2>>y2;
  sax=x1-x2;
  say=y1-y2;
  sax=pow(sax,2);
  say=pow(say,2);
  ans=sqrt(sax+say);
  cout<<setprecision(12)<<ans<<endl;
  return 0;
  
}
