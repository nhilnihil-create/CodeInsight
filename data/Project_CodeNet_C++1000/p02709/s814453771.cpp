#include<bits/stdc++.h>
#define ll long long
#define lld long long double
#define pb push_back
#define mp make_pair
#define M 1000000007
using namespace std;

const int N = 2005;
ll n;
ll memo[N][N];

ll f(int i, int l, int r, pair<ll, ll>a[]) {
	if (l > r) return 0;
	ll &ans = memo[i][l];
	if (ans != -1) return ans;
	//left
	ans = f(i + 1, l + 1, r, a) + a[i].first * abs(l - a[i].second);

	//right
	ans = max(ans, f(i + 1, l, r - 1, a) + a[i].first * abs(r - a[i].second));
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	cin >> n;
	pair<ll, ll>a[n];
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		a[i].first = x;
		a[i].second = i;
	}
	sort(a, a + n);
	reverse(a, a + n);
	cout << f(0, 0, n - 1, a);
	return 0;
}