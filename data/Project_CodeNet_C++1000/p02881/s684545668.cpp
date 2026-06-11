#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  ll n;
  cin >> n;
  ll ans = 1000000000005;
  ll m = (ll)sqrt(n);
  rep2(i, 1, m + 1) {
    if (n % i == 0) ans = min(ans, (i - 1) + (n / i - 1));
  }
  cout << ans << endl;

  return 0;
}