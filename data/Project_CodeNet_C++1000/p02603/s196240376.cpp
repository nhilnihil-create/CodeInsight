// D - Road to Millionaire
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N; cin>>N;
	vector<int> A(N+1, 0);
	rep(i, N) cin>>A[i];
	vector<int64_t> dp(N+1, 1000);
	rep(d, N)
		dp[d+1] = max(dp[d], dp[d] + dp[d]/A[d] * (A[d+1] - A[d]));
	cout<< dp[N] <<endl;
}
