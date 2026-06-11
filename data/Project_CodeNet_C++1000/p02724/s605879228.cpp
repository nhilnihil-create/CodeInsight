#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  ll x;
  cin >> x;
  ll ans = 0;
  ans += 1000 * (x/500);
  x %= 500;
  ans += 5 * (x/5);
  cout << ans << endl;

  return 0;
}
