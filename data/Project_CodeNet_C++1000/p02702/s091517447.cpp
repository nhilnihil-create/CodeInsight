#include <bits/stdc++.h>
using namespace std;

const int MOD = 2019;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  reverse(begin(S), end(S));

  vector<int> v(2020, 0);
  int curr = 0;
  int p = 1;
  v[0]++;
  for (int i = 0; i < N; ++i) {
    curr = (curr + (S[i] - '0') * p) % MOD;
    p = p * 10 % MOD;
    v[curr]++;
  }

  long long ans = 0;
  for (const auto& x: v) {
    ans += x * (x - 1) / 2;
  }
  cout << ans << endl;
}
