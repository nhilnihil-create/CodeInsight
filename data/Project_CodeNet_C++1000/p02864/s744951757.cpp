#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll H[314], dp[314][314], mx=1e18;

int main() {
	int N, K;
	cin >> N >> K;
	H[0]=H[N+1]=0;
	for(int i=1; i<=N; ++i) cin >> H[i];
	dp[0][0]=0;
	for(int i=1; i<=K; ++i) dp[0][i]=mx;
	for(int i=1; i<=N+1; ++i){
		for(int j=0; j<=K; ++j){
			dp[i][j]=min(mx, dp[i-1][j]+max(0LL, H[i]-H[i-1]));
			for(int k=1; i-1-k>=0 && j-k>=0; ++k){
				dp[i][j]=min(dp[i][j], dp[i-1-k][j-k]+max(0LL, H[i]-H[i-1-k]));
			}
		}
	}
	ll ans=mx;
	for(int i=0; i<=K; ++i) ans=min(mx, dp[N+1][i]);
	cout << ans << endl;
	return 0;
}