#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using Vl = vector<ull>;
#define rep(i, ns, ne) for (ull i = ns; i < ne; ++i)

int N;
Vl v;

void input() {
  cin >> N;
  v.resize(N);
  for (auto &e : v) cin >> e;
  sort(v.begin(), v.end());
}

void solve() {
  unsigned ans = 0;
  for (ull i = 0; i < N; ++i) {
    for (ull j = 0; j < i; ++j) {
      for (ull k = 0; k < j; ++k) {
        if ((v[i] != v[j]) && (v[j] != v[k]) && (v[i] < v[j] + v[k])) ans++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  input();
  solve();
  getchar();
  return 0;
}