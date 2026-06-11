#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = n / (a + b) * a;
  ll rem = n % (a + b);
  ans += min(a, rem);
  cout << ans;
}
