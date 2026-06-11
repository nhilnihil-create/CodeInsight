#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int X, N;
  cin >> X >> N;

  set<int> p;
  rep(i, N) {
    int pi;
    cin >> pi;
    p.insert(pi);
  }

  rep(i, N + 1) {
    if (!p.count(X - i)) {
      cout << X - i << endl;
      return 0;
    } else if (!p.count(X + i)) {
      cout << X + i << endl;
      return 0;
    }
  }
  return 0;
}