#include <bits/stdc++.h>
using namespace std;



int main() {
  int n; cin>>n;
  string s; cin>>s;
  
  int allR=0;
  for(int i=0; i<n; i++){
    allR += (s.at(i)=='R');
  }
  if(allR==n || allR==0){cout<<"0\n"; return 0;}
  
  int cw, cr;
  cw=0; cr=allR;
  for(int i=0; i<n; i++){
    bool isr=(s.at(i)=='R');
    cw+=1-isr; cr-=isr;
    if(cw==cr){
      cout<<cw<<endl;
      return 0;
    }
  }
}