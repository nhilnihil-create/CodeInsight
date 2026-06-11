#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT

ll N, M, P;

// i番目の要素を採用できるか否か
bool f(vector<ll> a, ll V, ll i) {
  if (i < P)
    return true;

  // printf("before a[%lld]=%lld: ", i, a[i]);
  // for (auto e : a) {
  //   cout << e << " ";
  // }
  // cout << endl;


  // 自分自身
  a[i] += M; V--;
  if (a[P-1] > a[i])
    return false;

  // 自分自身より小さいもの
  for (ll j=i+1; j<N; j++) if (V > 0) { a[j] += M; V--; }
  //t += (N-1 -i +1) * M;

  // 1 ~ P-1番目のものはどうでもよい
  for (ll j=0; j<P-1; j++)   if (V > 0) { a[j] += M; V--; }
  //t += (P-1) * M;

  if (V <= 0)
    return true;

  // P番目までは逆転したい -> j = P-1 ~ i-1 に、つまりできるだけ分散させたい
  ll t = 0;
  for (ll j=P-1; j<i; j++) {
    t += min(M, max(0ll, a[i] - a[j]));
  }

  return t >= M * V;
}

signed main() {
  ll V;
  cin >> N >> M >> V >> P;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];
  sort(begin(a), end(a), greater<ll>());
  ll ok = -1, ng = N;
  while (ok + 1 < ng) {
    ll m = (ok+ng)/2;
    if (f(a, V, m)) ok = m;
    else ng = m;
  }
  cout << ng << endl;
  return 0;
}
