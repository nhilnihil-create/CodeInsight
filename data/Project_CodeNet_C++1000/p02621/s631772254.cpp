#include <bits/stdc++.h>

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;

int N;
void input() { cin >> N; }
void solve() {
  N += N * N + N * N * N;
  cout << N << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}