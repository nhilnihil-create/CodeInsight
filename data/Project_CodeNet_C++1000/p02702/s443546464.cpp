#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 2019;

int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  ll power = 1;
  ll answer = 0;
  ll cur = 0;
  vector<int> remain(MOD);
  remain[0] = 1;
  for (auto s : S) {
    cur += (s-'0') * power;
    cur %= MOD;
    answer += remain[cur];
    remain[cur]++;
    power = power * 10 % MOD;
  }
  cout << answer << '\n';
  return 0;
}