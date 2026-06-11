#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
#define fst first
#define snd second
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}
inline int Log2(ll x) {int k; for(k=0; x>0; ++k) x>>=1; return k;} // number of binary digits
template<typename T> inline int count_between(vector<T>& a, T l, T r) {
  return lower_bound(all(a), r) - lower_bound(all(a), l); // [l, r)
}
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;


int main() {
  int n; cin >> n;
  vector<tuple<ld, ll, ll>> xy;
  rep(i, n) {
    int x, y; cin >> x >> y;
    if (x==0 && y==0) continue;
    xy.push_back(make_tuple(atan2(x, y), x, y));
  }
  sort(all(xy));
  n = xy.size();
  

  vector<pair<ll, ll>> s(n+1);
  rep(i, n) {
    s[i+1].fst += s[i].fst + get<1>(xy[i]);
    s[i+1].snd += s[i].snd + get<2>(xy[i]);
  }

  ll ans = 0;
  rep(j, n+1) rep(i, j+1) {
    ll sx = s[j].fst - s[i].fst;
    ll sy = s[j].snd - s[i].snd;
    chmax(ans, sx*sx + sy*sy);
    sx = s[n].fst - sx;
    sy = s[n].snd - sy;
    chmax(ans, sx*sx + sy*sy);
  }

  cout << setprecision(12);
  cout << sqrt(ans) << endl;
  return 0;
}
