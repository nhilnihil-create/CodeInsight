#include <iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>

#define LL	long long
using namespace std;
const int MAXN = 2010;
const int MAXA = 1e9;

pair<int, int> A[MAXN];
LL dp[MAXN][MAXN];
int N;
LL ans;

int main() {
	cin >> N;
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	
	sort(A+1, A+N+1, greater<pair<int,int>>());

	ans = 0;
	for(int k=1; k<=N; k++) {
		int len = N-k+1;
		//printf("len = %d\n", len);
		for(int i=1; i+len-1<=N; i++) {
			int j = i+len-1;
			if(len == 1) {
				ans = max(ans, dp[k-1][i] + 1LL*A[k].first*abs(A[k].second -i));
				continue;
			}
			// left
			dp[k][i+1] = max(dp[k][i+1], dp[k-1][i] + 1LL*A[k].first*abs(A[k].second -i));
			// right
			dp[k][i] = max(dp[k][i], dp[k-1][i] + 1LL*A[k].first*abs(A[k].second-j));
			//printf("f[%d][%d]=%d, f[%d][%d]=%d\n", k, i+1, dp[k][i+1], k, i, dp[k][i]);

		}
	}
	
	cout<<ans<<endl;
	return 0;
}