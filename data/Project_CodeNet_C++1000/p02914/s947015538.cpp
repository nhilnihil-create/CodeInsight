#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define FI(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (b); i >= (a); --i)
#define DEBUG(x) cerr << #x << ": " << (x) << '\n';

template <class T> vector<T> xor_span(vector<T> a) {
  int k = 0;
  for (int i = 0; i < 8 * int(sizeof(T)); i++) {
    auto p = find_if(a.begin() + k, a.end(), [i](T x) { return x & T(1) << i; });
    if (p == a.end()) continue;
    swap(a[k], *p);
    for (int j = 0; j < int(a.size()); j++)
      if (j != k && (a[j] & T(1) << i)) a[j] ^= a[k];
    k++;
  }
  return a.resize(k), a;
}

bool check(LL x, vector<LL> v) {
  while (x) {
    auto p = find_if(v.begin(), v.end(), [x](LL y) { return x & y; });
    if (p == v.end()) return false;
    x ^= *p;
    LL tt = *p;
    for (auto &y: v) y ^= tt;
    *p = v.back();
    v.pop_back();
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<LL> a(n);
  FI(i,0,n-1) scanf("%lld", &a[i]);
  LL ans = 0;
  for (LL x: a) ans ^= x;
  LL mask = 0;
  for (int i = 61; i >= 0; --i) {
    if (1LL << i & ans) continue;
    LL nmask = mask | 1LL << i;
    vector<LL> b;
    for (LL x: a) {
      LL y = x & nmask;
      if (y) b.push_back(y);
    }
    auto v = xor_span(b);
    LL tmp = 0;
    for (auto x: v) tmp ^= x;
    if (tmp == nmask) mask = nmask;
  }
  cout << ans + mask * 2LL << endl;
}
