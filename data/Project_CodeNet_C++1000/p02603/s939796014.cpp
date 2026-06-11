#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


int main(void) {
  ll N, mon = 1000, stock = 0;
  cin >> N;
  vector<ll> a(N);
  rep(i, N)
    cin >> a[i];
  rep(i, N) {
    if (i + 1 < N && a[i] < a[i+1]) {
      ll n = mon / a[i];
      stock += n;
      mon -= n * a[i];
    }
    if (i + 1 < N && a[i] > a[i+1]) {
      mon += stock * a[i];
      stock = 0;
    }
  }
  mon += a[N-1] * stock;
  stock = 0;
  cout << mon << endl;
  return 0;
}
