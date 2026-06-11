#include <bits/stdc++.h>

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;

int k;
void input() { cin >> k; }

void exit_end(int ans) {
  cout << ans << endl;
  exit(0);
}

//set version
void solve() {
  set<int> s;
  if (k % 2 == 0) exit_end(-1);
  int x = 7 % k;
  int i = 1;
  while (s.count(x) == 0) {
    if (x == 0) exit_end(i);
    s.emplace(x);
    x = (x * 10 + 7) % k;
    i++;
  }
  exit_end(-1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}