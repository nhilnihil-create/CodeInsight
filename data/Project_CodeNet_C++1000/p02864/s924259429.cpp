#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1LL<<56;
const int mxN = 305;
ll dp[mxN][mxN], H[mxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int N, K;
	cin>>N>>K;
	for(int i = 1; i <= N; i++){
		cin>>H[i];
	}
	for(int n = 0; n <= N; n++){
		for(int k = 0; k <= N; k++){
			dp[n][k] = inf;
		}
	}
	dp[0][0] = H[0] = 0;
	for(int n = 1; n <= N; n++){
		for(int k = 1; k <= n; k++){
			for(int m = 0; m < n; m++){
				dp[n][k] = min(dp[n][k], dp[m][k - 1] + max(0LL, H[n] - H[m]));
			}
		}
	}
	ll ans = inf;
	for(int n = 0; n <= N; n++){
		for(int k = N - K; k <= N; k++){
			ans = min(ans, dp[n][k]);
		}
	}
	cout<<ans<<endl;


	return 0;
}