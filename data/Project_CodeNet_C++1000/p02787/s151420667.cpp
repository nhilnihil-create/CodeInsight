#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)

using namespace std;

long long H, N;
long long A[1005];
long long B[1005];
long long dp[10005];

int main(){
	cin >> H >> N;
	rep(i, N) {
		cin >> B[i] >> A[i];
		//cin >> A[i] >> B[i];
	}

	rep(i, H + 5) dp[i] = LONG_MAX;

	dp[H] = 0;
	for(long long i = H; i >= 0; i--) {
		if(dp[i] != LONG_MAX) {
			rep(j, N) {
				long long next = max(0LL, i - B[j]);
				dp[next] = min(dp[next], dp[i] + A[j]);
			}
		}
	}
	cout << dp[0] << endl;
}
