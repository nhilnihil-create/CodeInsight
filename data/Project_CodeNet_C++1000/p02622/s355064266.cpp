#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define F first
#define S second
#define ld long double
#define rep(i,a,n) for (ll i= (a) ; i < (n); ++i)
#define vi vector<ll>
#define all(v) (v).begin(),(v).end()
#define M_PI 3.14159265358979323846
const ll MOD = 1e9 + 7;
const ll INF = 1e18L + 5;

void solve() {
	string s, t;
	cin >> s >> t;
	int ans = 0;
	rep(i, 0, s.size()) {
		if ( s[i] != t[i])
			ans++;
	}

	cout << ans<<endl;
}


int main() {

	int t = 1;

	//cin >> t;
	ll k = 1;
	while (t--) {
		//cout << "Case #" << k++ << ": ";
		solve();
	}
	return 0;
}
