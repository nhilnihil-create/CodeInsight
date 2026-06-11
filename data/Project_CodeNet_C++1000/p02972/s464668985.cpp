#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n;
  cin >> n;
  V<int> a(n);
  rep(i, n) cin >> a[i];

  V<int> b(n);
  for (int i = n - 1; i >= 0; i--) {
    int s = 0;
    for (int j = i; j < n; j += i + 1) s += b[j];
    if (s % 2 != a[i]) b[i] += 1;
  }
  int m = 0;
  rep(i, n) if (b[i] > 0) m++;
  cout << m << endl;
  rep(i, n) if (b[i] > 0) cout << i + 1 << endl;
}
