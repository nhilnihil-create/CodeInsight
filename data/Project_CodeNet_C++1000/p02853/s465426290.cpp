#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)

int main(){
  int n,k;
  cin>>n>>k;
  int ans=0;
  if(n==1) ans+=300000;
  else if(n==2) ans+=200000;
  else if(n==3) ans+=100000;
  if(k==1) ans+=300000;
  else if(k==2) ans+=200000;
  else if(k==3) ans+=100000;
  if(n==1 && k==1) ans+=400000;
  cout<<ans<<endl;
}