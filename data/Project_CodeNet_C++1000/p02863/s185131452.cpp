#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

int main()
{
	int N, T;
	int A[3010];
	int B[3010];

	cin >> N >> T;
	for(int i = 0; i < N; i++)
		cin >> A[i] >> B[i];
	
	int dp1[3010][3010];
	int dp2[3010][3010];
	for(int i = 0; i < N; i++)
	{
		for(int t = 0; t < T; t++)
		{
			dp1[i+1][t] = max(dp1[i+1][t], dp1[i][t]);
			if(t + A[i] < T)
				dp1[i+1][t+A[i]] = max(dp1[i+1][t+A[i]], dp1[i][t]+B[i]);
		}
	}
	for(int i = N; i > 0; i--)
	{
		for(int t = 0; t < T; t++)
		{
			dp2[i-1][t] = max(dp2[i-1][t], dp2[i][t]);
			if(t + A[i-1] < T)
				dp2[i-1][t+A[i-1]] = max(dp2[i-1][t+A[i-1]], dp2[i][t]+B[i-1]);
		}
	}

	int ans = 0;
	for(int i = 0; i < N; i++)
		for(int t = 0; t < T; t++)
			ans = max(ans, dp1[i][t] + dp2[i+1][T-1-t] + B[i]);

	cout << ans << endl;
	return 0;
}

