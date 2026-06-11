#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

string s;
int n, k;
vector <pair<int, int>> v;

int main() {	
	cin >> s >> k;
	n = ss(s);
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && s[i] == s[j]) j++;
		v.pb({s[i] - 'a', j - i});
		i = j;
	}
	if (ss(v) == 1) {
		printf ("%lld\n", (ll) n * k / 2);
		return 0;
	}
	if (v[0].fi != v.back().fi) {
		int sum = 0;
		for (auto it : v)
			sum += it.se / 2;
		printf ("%lld\n", (ll) sum * k);
		return 0;
	}
	ll res = 0;
	rep(i, 1, ss(v) - 2)
		res += (ll) k * (v[i].se / 2);
	int a = v[0].se; int b = v.back().se;
	res += (ll) (k - 1) * ((a + b) / 2);
	res += a / 2 + b / 2;
	printf ("%lld", res);
    return 0;
}

