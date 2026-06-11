#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n,r,ans;
  cin>>n>>r;
  if(n<11) ans=r+100*(10-n);
  else ans=r;
  cout<<ans<<endl;
}