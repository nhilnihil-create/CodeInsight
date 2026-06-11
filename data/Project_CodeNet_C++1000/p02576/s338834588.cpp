#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
  int N, X, T;
  cin >> N >> X >> T;

  cout << (N + X - 1) / X * T << endl;

  return 0;
}
