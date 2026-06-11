#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin,(a).rend()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	ll ans = 0;
	rep(i, n) {
		cin >> a[i];
		ans ^= a[i];
	}

	dunk(ans == 0 ? "Yes" : "No");

	return 0;
}