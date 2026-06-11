#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 998244353;
int dist[100100];
int d[100100];
int main() {
	int n;
	cin >> n;
	ll ans = 1;
	
	rep(i,n) cin >> d[i];
	if (d[0] != 0) ans = 0;
	dist[d[0]]++;
	sort(d,d+n);
	for (int i = 1; i < n; i++)
	{
		if (d[i] == 0) ans = 0;
		else {
			ans *= dist[d[i]-1];
			ans %= MOD;
			dist[d[i]]++;
		}
	}

	cout << ans << endl;
	return 0;
}