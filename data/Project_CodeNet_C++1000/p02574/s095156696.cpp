#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 1e6;

int lp[N + 1];
int cnt[N + 1];

void solve() {
  for (int i = 2; i <= N; i++) {
    if (lp[i]) continue;
    lp[i] = i;
    if (1LL * i * i > N) continue;
    for (int j = i * i; j <= N; j += i) {
      if (!lp[j]) lp[j] = i;
    }
  }
  int n, g; cin >> n;
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    if (i == 0) g = v;
    else g = __gcd(g, v);
    while (v != 1) {
      int p = lp[v];
      while (v % p == 0)
        v /= p;
      cnt[p]++;
    }
  }
  int flag = 1;
  for (int i = 2; i <= N; i++) {
    flag &= (cnt[i] <= 1);
  }
  if (flag)
    cout << "pairwise coprime";
  else if (g == 1)
    cout << "setwise coprime";
  else
    cout << "not coprime";
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
