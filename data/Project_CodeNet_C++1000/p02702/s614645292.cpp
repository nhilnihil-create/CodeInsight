#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  unordered_map<int, int> up;
  int num = 0;
  up[0]++;
  int x = 0, tot = 1;
  int mod = 2019;
  REP(i, S.size()) {
    x += (S[i] - '0') * tot;
    x %= mod;
    tot *= 10;
    tot %= mod;
    up[x]++;
  }
  int ans = 0;
  for (auto s : up) {
    ans += (s.second * (s.second - 1)) / 2;
  }
  cout << ans << endl;
}