#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long s,xone,yone,xtwo,ytwo,zero;
  zero=0;
  cin>>s;
  xtwo=1000000000;
  yone=s/1000000000;
  
  if(yone==1000000000){
    ytwo=yone;
    xone=0;
  }
  else{
    ytwo=yone+1;
    xone=s%xtwo;
  }
  cout<<xone;
  cout<<" "<<zero;
  cout<<" "<<zero;
  cout<<" "<<yone;
  cout<<" "<<xtwo;
  cout<<" "<<ytwo;
}