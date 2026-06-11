#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  ll a, b, n;
  cin >> a >> b >> n;
  ll ans = floor(a * min(b - 1, n) / b);
  cout << ans << endl;
  return 0;
}