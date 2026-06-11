#include<bits/stdc++.h>
#include<climits>

using namespace std;

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
#define fie(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define mod 998244353
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define ll long long
#define lld long long int
#define ALL(x) (x).begin(),(x).end()

typedef vector<lld> vi;
typedef vector<vector<lld>> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<lld, lld>> vpi;
typedef long long LL;

lld dp[2001];

lld solve(lld n) {
	if (n == 0) return dp[n] = 1;
	if (n == 1 || n == 2) return dp[n] = 0;
	if (dp[n] != -1) return dp[n];
	lld c = 0;
	for (lld i = 3; i <= n; i++) {
		if (n - i >= 0) c += solve(n - i);
		c %= MOD;
	}
	return dp[n] = c;

}

int main() {
	fast;
	cin.tie(0);
	lld n;
	cin >> n;
	if (n == 1 || n == 2) cout << "0" << endl;
	else {
		memset(dp, -1, sizeof(dp));
		cout << solve(n) << endl;
	}
}






