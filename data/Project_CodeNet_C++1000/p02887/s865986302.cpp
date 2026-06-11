#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  string T;
  rep(i, N) {
    if (i >= 1 && S[i - 1] != S[i]) T += S[i];
  }
  cout << T.size() + 1 << endl;
  return 0;
}