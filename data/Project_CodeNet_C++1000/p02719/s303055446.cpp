#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  ll cmp = 0;
  cmp = n % k;
  ans = min(cmp, abs(cmp-k));
  cout << ans << endl;
  return 0;
}