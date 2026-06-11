#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll x;
  cin >> x;
  ll ans = (x / 500) * 1000;
  x %= 500;
  ans += (x / 5) * 5;
  cout << ans;
}
