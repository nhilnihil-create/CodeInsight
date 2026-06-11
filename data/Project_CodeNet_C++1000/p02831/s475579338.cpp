#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll a, b;
  cin >> a>> b;
  ll c = __gcd(a,b);
  ll ans = a * b / c;
  cout << ans << endl;
  return 0;
}