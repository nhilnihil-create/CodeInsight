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

using P = pair<ll, ll>;

int main(void){
  ll H, W, M;
  cin >> H >> W >> M;
  vector<ll> h(M), w(M);
  map<P, ll> mp;
  REP(i, M){
    cin >> h[i] >> w[i];
    h[i]--; w[i]--;
    mp[P(h[i], w[i])]++;
  }
  vector<ll> a(H, 0), b(W, 0);
  REP(i, M) a[h[i]]++, b[w[i]]++;

  ll c = *max_element(ALL(a));
  ll d = *max_element(ALL(b));
  vector<ll> p, q;
  REP(i, H) if(a[i] == c) p.emplace_back(i);
  REP(i, W) if(b[i] == d) q.emplace_back(i);
  
  ll n = p.size(), m = q.size();
  ll ans = c+d-1;
  REP(i, n) REP(j, m){
    if(mp[P(p[i], q[j])] == 0){
      ans = c+d;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}