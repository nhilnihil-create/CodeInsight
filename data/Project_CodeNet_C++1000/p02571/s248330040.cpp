#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define forn(i,n) for(int i=0;i<n;i++)
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

///-----------------------------------------------------------------------------------------------------------------///

int mod(long long x) {
	return ((x % M + M) % M);
}
int add(int a, int b) {
	return mod(mod(a) + mod(b));
}
int diff(int a, int b) {
	return mod(mod(a) - mod(b));
}

int mul(int a, int b) {
	return mod(mod(a) * mod(b));
}

int modPow(int a, int b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % M;
	int res = 1;
	while (b) {
		if (b % 2 == 1)
			res = mul(res, a);
		a = mul(a, a);
		b = b / 2;
	}
	return res;
}

////------------------------------------------------------------------------------------------------------------------////////

void solve() {

	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();

	int st = 0;
	int ans = INT_MAX;



	while (st <= n - m) {
		int cnt = 0;
		for (int e = 0; e < m; e++) {
			if (s[e + st] != t[e]) {

				cnt++;
			}

		}
		ans = min(ans, cnt);
		st++;
	}

	cout << ans << endl;

}



int32_t main() {

	fastio;

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	// int t; cin >> t;/
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}