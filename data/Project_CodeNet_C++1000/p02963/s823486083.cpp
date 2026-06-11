#include<bits/stdc++.h>
using namespace std;
const int MAX=1000000000;
int main(){
  
  long long s;
  cin>>s;
  
  long long xa=0,xb=MAX,xc,ya=0,yb=1,yc;
  long long aa,mod;
  yc=s/MAX+1;
  mod=s%MAX;
  xc=MAX-mod;
  if(s==1000000000000000000){
  	xb=MAX;
    xc=0;
    yb=0;
    yc=MAX;
  } 
  cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<" "<<xc<<" "<<yc<<" "<<endl;

}