#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll n, d, a, k, s, t;
  in3(n, d, a);
  vector<pair<ll, ll>> c(n);
  rep(i, n)
    in2(c[i].first, c[i].second);
  c.pb(make_pair(9999999999999, 999999999999999));
  sort(all(c));
  d = d * 2;
  vector<ll> f(n), e(n + 1, 0);
  s = 0;
  t = 1;
  while(s < n){
    while(c[t].first <= c[s].first + d)
      t++;
    f[s] = t;
    s++;
  }
  s = 0; // damage
  k = 0;
  rep(i, n){
    s -= e[i];
    if(s >= c[i].second)
      continue;
    t = (c[i].second - s + a - 1) / a;
    s += t * a;
    e[f[i]] += t * a;
    k += t;
  }
  out(k);
  memi;
}
