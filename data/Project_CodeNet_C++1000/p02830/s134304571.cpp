#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;
  rep(i, N) cout << S[i] << T[i];

  return 0;
}