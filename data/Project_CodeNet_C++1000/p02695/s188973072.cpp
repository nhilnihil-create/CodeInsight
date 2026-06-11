#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = 10 + 7;
const int Q = 50 + 7;
int n, m, q;
int a[Q], b[Q], c[Q], d[Q];
int v[N];
int sol;

int get() {
  int sol = 0;
  for (int i = 1; i <= q; i++) {
    if (v[b[i]] - v[a[i]] == c[i]) {
      sol += d[i];
    }
  }
  return sol;
}

void gen(int pos) {
  if (pos == n + 1) {
    sol = max(sol, get());
    return;
  }
  for (int j = v[pos - 1]; j <= m; j++) {
    v[pos] = j;
    gen(pos + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  v[0] = 1;
  cin >> n >> m >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  gen(1);
  cout << sol << "\n";
  return 0;
}
