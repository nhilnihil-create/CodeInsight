#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size(), M = 2019;
  reverse(S.begin(), S.end());
  vector<int> V(M);
  int dig = 1, sum = 0;
  V.at(sum)++;
  for (int i = 0; i < N; i++) {
    sum += (S.at(i) - '0') * dig;
    sum %= M;
    dig *= 10;
    dig %= M;
    V.at(sum)++;
  }
  int ans = 0;
  for (auto v : V) ans += v * (v - 1) / 2;
  cout << ans << "\n";
}