#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;
  string s;
  unordered_map<string, int> hash;
  rep(i, N) {
    cin >> s;
    sort(s.begin(), s.end());
    hash[s]++;
  }

  ll ans = 0;
  for (auto& p : hash) {
    int num = p.second;
    ans += (ll)num * (num - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}