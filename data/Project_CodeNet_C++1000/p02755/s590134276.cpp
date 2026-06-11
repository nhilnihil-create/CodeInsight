#define LOCAL

#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f

using llong = long long;
using PII = pair<int, int>;

const llong MOD = 123456789LL;
const double PI = acos(-1);

int main() {
	IOS;
	llong ll = 0, rr = INF;
	llong ans = -1;
	llong a, b; cin >> a >> b;
	for (int i = 1; i <= 10000; i++) {
		if (i * 8 / 100 == a && i * 10 / 100 == b) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << ans;
}