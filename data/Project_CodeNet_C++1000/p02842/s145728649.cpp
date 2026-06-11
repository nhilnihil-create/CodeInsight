#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = (ss); i <= (ee); ++i)

void solve() {
  int N;
  cin >> N;
  rep(i, 1, N) {
    if (int(i * 1.08) == N) {
      cout << i << endl;
      return;
    };
  }
  cout << ":(" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}