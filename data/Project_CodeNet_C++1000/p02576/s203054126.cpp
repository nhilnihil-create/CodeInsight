#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x,t;
  cin>>n>>x>>t;
  int ans;
  ans = (n/x)*t;
  if(n%x) ans += t;
  cout<<ans<<endl;
  return 0;
}