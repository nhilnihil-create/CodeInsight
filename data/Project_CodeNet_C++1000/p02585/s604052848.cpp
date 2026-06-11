#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n, k;
  cin >> n >> k;
  vector<ll> p(n), c(n);
  REP(i, n) cin >> p[i], p[i]--;
  REP(i, n) cin >> c[i];
  ll ans = -INF;
  REP(si, n){
    ll x = si;
    vector<ll> s;
    ll total = 0;
    while(1){
      x = p[x];
      s.emplace_back(c[x]);
      total += c[x];
      if(x == si) break;
    }
    ll l = s.size();
    ll now = 0;
    REP(i, l){
      now += s[i];
      if(i+1 > k) break;
      ll t = now;
      if(total > 0){
        ll e = (k-i-1)/l;
        t += total*e;
      }
      chmax(ans, t);
    }
  }
  cout << ans << endl;
  return 0;
}