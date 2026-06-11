#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  long N = S.size(), M = 1e9+7, ans = 1;
  for (long i = N - 1, d = 1; i >= 0; i--, d = d * 3 % M) {
    if (S.at(i) == '1') ans = (ans * 2 + d) % M;
  }
  cout << ans << "\n";
}