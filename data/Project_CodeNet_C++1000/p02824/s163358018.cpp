#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e5+10;

ll n, m, v, p;
int a[N];

bool check(int x) { // can x be selected?
  ll score = a[x] + m;
  ll rem = 1LL * (v-1) * m;
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (i == x) continue;
    if (a[i] > score) {
      k++;
      rem -= m;
    } else if (k < p-1) {
      k++;
      rem -= m;
    } else {
      rem -= min(m, score - a[i]);
    }
  }
  return k <= p-1 && rem <= 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> v >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<int>());
  int l = p, r = n-1, ans = p-1;
  while (l <= r) {
    int m = (l+r)/2;
    if (check(m)) {
      ans = m;
      l = m+1;
    } else r = m-1;
  }
  cout << ans+1 << nl;
}
