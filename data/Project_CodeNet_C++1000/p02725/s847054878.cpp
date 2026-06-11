#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  ll n,k,ans=0;
  cin>>k>>n;
  ll a[n];
  for(ll i=0;i<n;i++)
    cin>>a[i];
  ll min=0;
  for(ll i=0;i<n;i++){
    ll v=0;
    if(i<n-1){
      v=a[i+1]-a[i];
      ans+=v;
    }
    else{
      v=k-a[i]+a[0];
      ans+=v;
    }
    if(min<v)
      min=v;
  }
  cout<<ans-min;
  return 0;
}
