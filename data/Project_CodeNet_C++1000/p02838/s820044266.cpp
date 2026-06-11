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
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
const ll MOD = 1e9 + 7;
const ll MAX_B = 62;
signed main(){
  init_io();
  ll n,ans=0;
  cin >> n;
  vector<ll> a(n);
  vector<vector<ll>> bsum(n+1,vector<ll>(MAX_B,0));
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=n-1;i>=0;i--){
    bsum[i] = bsum[i+1];
    for(ll j=0;j<MAX_B;j++){
      if(a[i]&(1ll<<j)){
        bsum[i][j]++;
        bsum[i][j] %= MOD;
      }
    }
  }
  for(int i=0;i<n;i++){
    ll ad=1;
    for(ll j=0;j<MAX_B;j++){
      if(a[i]&(1ll<<j)){
        ans += ad * ((n-i-1)-bsum[i+1][j]);
      }else{
        ans += ad * (bsum[i+1][j]);
      }
      ans %= MOD;
      ad *= 2;
      ad %= MOD;
    }
  }
  cout << ans << endl;
}
