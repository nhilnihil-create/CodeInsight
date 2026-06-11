#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORr(i, k, n) for(int i = (k); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORr(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

int main(void){
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  REP(i, n) cin >> a[i];

  ll sum = 0;
  REP(i, n) sum += a[i];

  set<ll> candidates;
  for(int i = 1; i*i <= sum; i++){
    if(sum % i == 0){
      candidates.insert(i);
      candidates.insert(sum/i);
    }
  }
  ll ans = 1;
  for(ll x : candidates){
    ll need;
    vector<ll> r(n);
    REP(i, n) r[i] = a[i] % x;
    sort(ALL(r));
    ll rSum = 0;
    REP(i, n) rSum += x - r[i];
    ll lSum = 0;
    need = 1e18;
    REP(i, n){
      lSum += r[i];
      rSum -= x - r[i];
      chmin(need, max(lSum, rSum));
    }
    if(need <= k) chmax(ans, x);
  }
  cout << ans << endl;
  return 0;
}