#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;cin >> n >> k;
  vector<ll> a(n),sum(n+1);
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum[i+1]=sum[i]+a[i];
  }
  for(ll i=0;i<n+1;i++){
    sum[i]=(sum[i]+n*k-i)%k;
  }
  map<int,int> mp;
  ll ans=0;
  for(int i=0;i<=n;i++){
    ans+=mp[sum[i]];
    mp[sum[i]]++;
    if(i>=k-1){
      mp[sum[i-(k-1)]]--;
    }
  }
  cout << ans << endl;
}