#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, x, t, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x >> t;
	while (n) {
		n -= x;
		ans += t;
		if (n < 0)n = 0;
	}
	cout << ans << endl;
	return 0;
}