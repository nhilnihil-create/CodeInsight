#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  int n, tmp;
  cin >> n;
  vector<int> aj;
  vector<int> ai;
  aj.push_back(0);
  ai.push_back(0);
  rep(j, n) {
    cin >> tmp;
    aj.push_back(j + 1 - tmp);
    ai.push_back(j + 1 + tmp);
  }
  sort(aj.begin(), aj.end());
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (upper_bound(aj.begin(), aj.end(), ai[i]) - aj.begin()) - (lower_bound(aj.begin(), aj.end(), ai[i]) - aj.begin());
  }
  cout << ans << endl;

  return 0;
}
