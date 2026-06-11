// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,k,ans=0;
  cin >> n >> k;
  vector<ll> a(n),s(n+1,0);
  map<ll,ll> mp;
  for(int i=0;i<n;i++){
    cin >> a[i];
    s[i+1] = s[i]+a[i];
  }
  mp[0]++;
  for(int i=1;i<=n;i++){
    ll v = i-k,vv=(s[i]-i)%k;
    if(v>=0) mp[(s[v]-v)%k]--;
    ans += mp[vv];
    mp[vv]++;
  }
  cout << ans << endl;
}
