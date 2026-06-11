#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define ld 	 long double
#define F 	 first
#define S 	 second
#define P 	 pair<int,int>
#define pb 	 push_back
#define mod  1000000007
#define inf  1e18
#define endl '\n'
const int N = 2e3 + 5; //change it when needed
int cache[N][N];
P a[N];
int n;
int dp(int i, int l, int r) {
	if (l > r) {
		return 0;
	}
	int &ans = cache[i][l];
	if (ans != -1)return ans;
	ans = 0;
	//put it at left part
	ans = dp(i + 1, l + 1, r) + a[i].F * abs(a[i].S - l);
	//put it at right part
	ans = max(ans, dp(i + 1, l , r - 1) + a[i].F * abs(a[i].S - r));

	return ans;
}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = {x, i};
	}
	memset(cache, -1, sizeof(cache));
	sort(a, a + n);
	reverse(a, a + n);

	cout << dp(0, 0, n - 1);
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t; while (t--)
	solve();
	return 0;
}