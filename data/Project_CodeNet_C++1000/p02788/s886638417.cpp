#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
const long long INF = 1LL<<60;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
};

int main(){
  int N, D, A;
  cin >> N >> D >> A;
  vector<P> p(N);
  rep(i, N) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());

  ll ans = 0;
  BIT<ll> bit(N+1);
  rep(i, N){
    ll x = p[i].first;
    ll h = p[i].second;
    h -= bit.sum(i);
    if(h<=0) continue;
    ll num = (h+A-1) / A;
    ans += num;
    ll damage = num * A;
    bit.add(i, damage);
    int rx = min(x+2*D, 1001001001ll);
    rx += 1; // 1-indexedに直す
    int j = upper_bound(p.begin(), p.end(), P(rx, -1)) - p.begin();
    bit.add(j, -damage);
  }

  cout << ans << endl;

  return 0;
}
