#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll h;
  cin >> h;
  ll a = 1;
  while (a <= h) {
    a *= 2;
  }
  ll ans = a - 1;
  cout << ans << endl;
  return 0;
}