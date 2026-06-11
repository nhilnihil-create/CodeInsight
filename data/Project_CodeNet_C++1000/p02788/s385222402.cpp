#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

const int INF = 1001001001;

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
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main() {
  int n, d, a;
  cin >> n >> d >> a;
  vector<pair<ll, int>> X(n);
  rep(i, n) cin >> X[i].first >> X[i].second;
  sort(X.begin(), X.end());
  BIT<ll> bitree(n+1);
  ll ans = 0;
  int i = 0;
  while (i < n) {
    ll t = X[i].first + 2 * d;
    int idx = upper_bound(X.begin(), X.end(), make_pair(t, INF)) - X.begin();
    int num = (X[i].second-bitree.sum(i)+a-1) / a;
    ans += num;
    ll damage = num * a;
    bitree.add(i, damage);
    bitree.add(idx, -damage);
    while (i<n && bitree.sum(i) >= X[i].second) ++i;
  }
  cout << ans << endl;
  return 0;
}