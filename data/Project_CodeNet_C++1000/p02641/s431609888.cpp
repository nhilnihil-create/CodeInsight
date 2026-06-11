#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int X, N;
  cin >> X >> N;
  vector<int> p(N);
  rep(i, N) cin >> p[i];

  if (N == 0) {
    cout << X << endl;
    return 0;
  }

  for (int i = 0; i <= N; i++) {
    auto it2 = find(p.begin(), p.end(), X - i);
    if (it2 == p.end()) {
      cout << X - i << endl;
      return 0;
    }
    auto it3 = find(p.begin(), p.end(), X + i);
    if (it3 == p.end()) {
      cout << X + i << endl;
      return 0;
    }
  }

  return 0;
}