#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)

ll N, xors = 0;
vector<ll> v;
void input() {
  cin >> N;
  v.resize(N);
  for (auto &e : v) {
    cin >> e;
    xors ^= e;
  }
}

void solve() {
  rep(i, 0, N) {
    ll x = 0;
    cout << (xors ^ v[i]);
    if (i == N - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}