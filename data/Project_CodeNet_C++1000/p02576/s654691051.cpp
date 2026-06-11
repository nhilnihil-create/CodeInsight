#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, X, T;
  cin >> N >> X >> T;

  cout << T * (N / X + min(N % X, 1)) << endl;

  return 0;
}
