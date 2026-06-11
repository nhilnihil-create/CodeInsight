#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int>mp;
vector<ll>v;
int main(){
  int n,k;cin>>n>>k;
  ll pre[n+2];
  pre[0]=0;
  for(int i=0;i<n;i++){
    ll a;cin>>a;v.push_back(a);
    pre[i+1]=pre[i]+a-1;
    pre[i+1]%=k;
  }
  mp[0]++;
  ll ans=0;
  for(int i=1;i<=n;i++){
    if(i>=k){
      mp[pre[i-k]]--;
    }
    ans+=mp[pre[i]];
    mp[pre[i]]++;
  }
  cout<<ans;
  return 0;
}