#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int S;
  cin>>S;
  int a=0,b=1000000000;
  while(abs(a-b)>1){
    int c=(a+b)/2;
    if(c*c<=S)
      a=c;
    else
      b=c;
  }
  if(a*a>=S)
    cout<<a<<" 1 "<<a*a-S<<' '<<a;
  else
    cout<<b<<" 1 "<<b*b-S<<' '<<b;
  cout<<" 0 0\n";
}