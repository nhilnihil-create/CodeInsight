#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[200009];
map<ll,ll>mp;

int main(){
  ll n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    sum[i+1]=sum[i]+a;
  }
  ll ans=0;
  for(int i=0;i<=n;i++){
    sum[i]=sum[i]-i;
    sum[i]%=k;
    if(i-k>=0){
      mp[sum[i-k]]--;
    }
    ans+=mp[sum[i]];
    mp[sum[i]]++;
  }
  cout<<ans<<endl;
  return(0);
}
