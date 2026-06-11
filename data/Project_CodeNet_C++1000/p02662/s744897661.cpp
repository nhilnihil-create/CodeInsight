/*
    JAI JAGANNATH!
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<lli>
#define mii             map<lli,lli>
#define pqb             priority_queue<lli>
#define pqs             priority_queue<lli,vi,greater<lli> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            lli x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

void ss()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
lli add(lli a, lli b) {
	return ((a % mod) + (b % mod)) % mod;
}
void solve() {
	lli n, s;
	cin >> n >> s;
	vector <lli> v(n + 1);
	for (lli i = 1; i <= n; i++) cin >> v[i];
	vector < vector <lli >> dp(n + 1, vector <lli>(s + 1));
	dp[0][0] = 1;
	for (lli i = 1; i <= n; i++) {
		for (lli j = 0; j <= s; j++) {
			dp[i][j] = add(dp[i][j], dp[i - 1][j]);
			dp[i][j] = add(dp[i][j], dp[i - 1][j]);
			lli x = j + v[i];
			if (x <= s) {
				dp[i][x] = add(dp[i - 1][j], dp[i][x]);
			}
		}
	}
	cout << dp[n][s] << endl;;
}
int main()
{
	ss();
	solve();
	return 0;
}