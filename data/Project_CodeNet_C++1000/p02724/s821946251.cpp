#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  ll ans;
  ans=n/500;
  n-=ans*500;
  ans*=1000;
  ans+=n/5*5;
  cout<<ans<<endl;
  return 0;
}
