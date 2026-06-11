#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;

int main() {
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n,0);
	vector<int> b(n,0);
	ll lcm = 1;
	rep(i,n) {
		cin >> a[i];
		int x = a[i];
		while (x % 2 == 0)
		{
			x /= 2; 
			b[i]++;
		}
		lcm = a[i] / __gcd(a[i],lcm) * lcm;
	} 

	rep(i,n-1) {
		if (b[i] != b[i+1]) {
			cout << 0 << endl;
			return 0;
		}
	}
	ll ans = (2*m/lcm + 1) / 2;
	cout << ans << endl;


	return 0;
}