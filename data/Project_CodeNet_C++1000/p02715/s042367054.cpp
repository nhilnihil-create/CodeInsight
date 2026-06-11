#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x) //counts no of zeroes in binary rep
#define zrobits(x)      __builtin_ctzll(x) // count no of zeroes to right of first set bit
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

const int sz = 1e5 + 2;
// pbds works as set data structure. USE pbds.find_by_order() to get element randomly. it returns iterator
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int pwmd(int a, int b) {
	if (a == 1)
		return 1;
	if (b == 0)
		return 1;
	int ans = pwmd(a, b >> 1);
	ans = (ans % mod * ans % mod) % mod;
	if (b & 1)
		return (ans * a) % mod;
	else
		return ans;
}



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n = 0; cin >> n;
	int k = 0; cin >> k;
	int dp[sz]; // dp[i] stores the frequency of sequences which has gcd i
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	// iterate reverse because we need to subtract the frequency of sequence related to multiples of i
	for (int i = k; i >= 1; --i) {
		dp[i] = pwmd(k / i, n);
		//remove the count of 2*i,3*i,4*i......
		for (int j = 2 * i; j <= k; j += i)
			dp[i] = (dp[i] - dp[j] + mod) % mod;
		ans = (ans % mod + (dp[i] % mod * i % mod ) % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}