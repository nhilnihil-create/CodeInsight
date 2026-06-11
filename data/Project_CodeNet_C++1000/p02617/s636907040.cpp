#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin>>n;
  ll ans=0;
  for(ll i=1;i<=n;i++){
    ans+=i*(n+1-i);
  }
  for(int i=0;i<n-1;i++){
    ll x,y;
    cin>>x>>y;
    if(x>y){
      swap(x,y);
    }
    ans-=x*(n-y+1);
  }
  cout<<ans<<endl;
}