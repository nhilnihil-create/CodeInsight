#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (a%2 != b%2) {
		ll ans = min(b-1, n-a);
		ans = min(ans, (a+b-1)/2);
		ans = min(ans, (n-((a+b-1)/2)));
		cout << ans << endl;
	} else {
		ll ans = min(b-1, min(n-a, (a+b)/2-a));
		cout << ans << endl;
	}
	return 0;
}