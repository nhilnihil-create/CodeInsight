#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int N = 1000007, inf = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll ans = max({a * c, a * d, b * c, b * d});
  cout << ans << endl;
}