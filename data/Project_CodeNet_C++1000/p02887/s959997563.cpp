#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n;
  string s;
  cin >> n >> s;
  vector<pair<char, int>> vec;
  vec.emplace_back(s[0], 0);
  rep(i, s.size()) {
    if (vec.back().first == s[i]) {
      vec.back().second++;
    } else {
      vec.emplace_back(s[i], 1);
    }
  }
  cout << vec.size() << endl;
  return 0;
}
