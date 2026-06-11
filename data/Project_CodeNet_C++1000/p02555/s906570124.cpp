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

lld dp[2001][2001];

lld solve(lld n, lld l) {
	if (n < 0 || n == 1 || n == 2 || l < 0) return 0;
	if ((l == 0 && n != 0) || (n == 0 && l != 0)) return dp[n][l] = 0;
	if (n == 0 && l == 0) {
		return dp[n][l] = 1;
	}
	lld c = 0;
	if (dp[n][l] != -1) return dp[n][l];
	c += solve(n - 1, l);
	c %= MOD;
	c += solve(n - 3, l - 1);
	c %= MOD;
	return dp[n][l] = c;

}

int main() {
	fast;
	cin.tie(0);
	lld n;
	cin >> n;
	if (n == 1 || n == 2) cout << "0" << endl;
	else {
		memset(dp, -1, sizeof(dp));
		lld cnt = 0;
		for (lld i = 1; i <= (n / 3) + 1; i++) {
			cnt += solve(n, i);
			cnt %= MOD;
		}
		cout << cnt << endl;
	}
}






