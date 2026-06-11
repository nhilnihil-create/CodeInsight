#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll a, b, c, k, ans;
  cin >> a >> b >> c >> k;
  ans = min(a, k);
  k = k - a - b;
  if(k > 0)
    ans -= k;
  cout << ans;
}
