#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int dp[1000010];
int dp2[1000010];

signed main() {
	int n;
	rep(i, 0, 1000010) {
		dp[i] = 10;
		dp2[i] = 10000000;
	}
	dp[0] = 0;
	dp2[0] = 0;
	rep(i, 1, 200) {
		int a = i*(i + 1)*(i + 2) / 6;
		if (a > 1000000) break;
		rep(j, 0, 1000001) {
			if (j + a > 1000000) break;
			dp[j + a] = min(dp[j + a], dp[j] + 1);
			if (a % 2 == 0) continue;
			dp2[j + a] = min(dp2[j + a], dp2[j] + 1);
		}
	}
	while (cin >> n && n) {
		cout << dp[n] << " " << dp2[n] << endl;
	}
}