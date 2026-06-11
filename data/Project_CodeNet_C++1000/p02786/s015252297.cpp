#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007

int main() {
  ll h;
  cin >> h;
  ll hp = h;
  ll num = 1;
  ll ans = 0;
  while (hp > 0) {
    ans += num;
    hp /= 2;
    num *= 2;
  }
  cout << ans << endl;

  return 0;
}
