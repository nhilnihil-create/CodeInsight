// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
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
  ll n,ans=0;
  multiset<ll> idx_set;
  cin >> n;
  vector<ll> p(n),val(n+1);
  for(int i=0;i<n;i++){
    cin >> p[i];
    val[p[i]] = i+1;
  }
  idx_set.insert(0);
  idx_set.insert(0);
  idx_set.insert(n+1);
  idx_set.insert(n+1);
  idx_set.insert(val[n]);
  for(int i=n-1;i>0;i--){
    auto aft0 = idx_set.upper_bound(val[i]);
    auto bef0 = aft0;
    bef0--;
    auto aft1 = aft0;
    aft1++;
    auto bef1 = bef0;
    bef1--;
    ll b0idx = *bef0,b1idx = *bef1,a0idx = *aft0,a1idx = *aft1;
    ans += i*(b0idx-b1idx)*(a0idx-val[i]);
    ans += i*(a1idx-a0idx)*(val[i]-b0idx);
    idx_set.insert(val[i]);
  }
  cout << ans << endl;
}
