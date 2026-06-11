#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

vector<ll> z_algorithm(const string &s) {
  vector<ll> prefix(s.size());
  for (ll i = 1, j = 0; i < s.size(); i++) {
    if (i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      ll k = max(0LL, j + prefix[j] - i);
      while (i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (ll)s.size();
  return prefix;
}
int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  string s;
  cin >> s;

  ll ans = 0;

  for (ll i = 0; i < s.size() - 1; i++) {
    // cout << "# " << i << endl;
    auto pre = z_algorithm(s.substr(i));
    // for (ll i = 0; i < pre.size(); i++) {
    //   cout << pre[i] << endl;
    // }

    for (ll i = 1; i < pre.size(); i++) {
      ll tmp = min(i, pre[i]);
      ans = max(ans, tmp);
    }
  }

  // cout << "----" << endl;
  cout << ans << endl;
}
