#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

int N;
vector<int> v, a;

void input() {
  cin >> N;
  a.resize(N);
  for (auto &e : a) cin >> e;
  sort(a.begin(), a.end());
  v.resize(a.back() + 1, true);
}

void solve() {
  int ans = 0;
  int b = -1;
  for (auto e : a) {
    if (v[e] == false) {
      b = e;
      continue;
    }
    if (b == e) {
      v[e] = false;
      continue;
    } else {
      b = e;
    }
    for (int i = e * 2; i < v.size(); i += e) { v[i] = false; }
  }
  for (auto e : a) {
    if (v[e]) ans++;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}