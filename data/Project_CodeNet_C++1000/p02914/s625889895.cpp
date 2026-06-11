#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define FI(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (b); i >= (a); --i)
#define DEBUG(x) cerr << #x << ": " << (x) << '\n';

template <class T> vector<T> xor_span(vector<T> a) {
  int k = 0;
  for (int i = 8 * int(sizeof(T)) - 1; i >= 0; --i) {
    auto p = find_if(a.begin() + k, a.end(), [i](T x) { return x & T(1) << i; });
    if (p == a.end()) continue;
    swap(a[k], *p);
    for (int j = 0; j < int(a.size()); j++)
      if (j != k && (a[j] & T(1) << i)) a[j] ^= a[k];
    k++;
  }
  return a.resize(k), a;
}

int main() {
  int n;
  cin >> n;
  vector<LL> a(n);
  FI(i,0,n-1) scanf("%lld", &a[i]);
  LL ans = 0;
  for (LL x: a) ans ^= x;
  for (LL &x: a) {
    for (int i = 0; i < 60; ++i) {
      if (ans & 1LL << i) {
        if (x & 1LL << i) x ^= 1LL << i;
      }
    }
  }
  auto v = xor_span(a);
  LL mask = 0;
  for (LL x: v) mask = max(mask, mask ^ x);
  cout << ans + mask * 2 << endl;
}
