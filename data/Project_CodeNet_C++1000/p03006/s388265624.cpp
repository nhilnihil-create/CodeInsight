#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  ll n;
  cin >> n;
  vector<pp> a(n);
  rep(i,n){
    ll b,c;
    cin >> b >> c;
    a[i] = pp(b,c);
  }
  map<pp,ll> hhh;
  rep(i,n)for(ll j = i+1;j<n;j++){
    ll dx = a[i].first-a[j].first;
    ll dy = a[i].second-a[j].second;
    hhh[pp(dx,dy)] ++;
    hhh[pp(-dx,-dy)] ++;
  }
  ll ans = 0;
  for(auto i:hhh) ans = max(ans, i.second);
  cout << n - ans << endl;
    
  return 0;
}



