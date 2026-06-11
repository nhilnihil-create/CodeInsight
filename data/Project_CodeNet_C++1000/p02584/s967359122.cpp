#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repbit(bit,n) for (int bit = 0; bit < (1<<n); bit++)
using namespace std;
typedef long long ll;

//const int INF = 1001001001;
//const ll INF18 = 1000000000000000000;
const ll INF15 = 1000000000000000;

int main() {
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);

	ll ans;
	ll min_cand;
	min_cand = min(k, x/d);
	k -= min_cand;
	ans = x - min_cand*d;

	if (k % 2 != 0) ans = abs(ans - d);
	cout << ans << endl;
	return 0;
}
