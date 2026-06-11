#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO;
	
	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> d1(n+1), d2(m+1);
	d1[0] = d2[0] = 0;
	for (int i = 1; i <= n; ++i) {
		ll x; cin >> x;
		d1[i] = d1[i-1] + x;
	}
	for (int i = 1; i <= m; ++i) {
		ll x; cin >> x;
		d2[i] = d2[i-1] + x;
	}
	
	ll ans= 0, j = 0;
	
	for (int i = 0; i < n+1; ++i) {
		ll current = k - d1[i];
		j = 0;
		if (current < 0) 
			break;
		ll low = 1, high = m;
		while (low <= high) {
			ll mid = low + (high - low)/2;
			if (d2[mid] <= current) {
				low = mid + 1;
				j = mid;
			}
			else {
				high = mid -1;
			}
		}
		ans = max(ans, i + j);
	}
	cout << ans;		
		
	
}
