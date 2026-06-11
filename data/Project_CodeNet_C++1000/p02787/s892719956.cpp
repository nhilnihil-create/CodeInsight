#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 1005;
const int MAX_dp = 20010;
int A[MAX_N],B[MAX_N];
ll dp[MAX_dp];

int main()
{
	int H,N;
	cin >> H >> N;
	rep(i,N)
	{
		cin >> A[i] >> B[i];
	}
	dp[0] = 0;
	rep(i,MAX_dp-1)
	{
		dp[i+1] = 1e9; 
	}
	rep(i,MAX_dp-1)
	{
		rep(j,N)
		{
			if (i+1 >= A[j])
			{
				dp[i+1] = min(dp[i+1],dp[i+1-A[j]]+B[j]);
			}
		}
	}
	ll ans = 1e9;
	for (int i = H; i < MAX_dp; ++i)
	{
		ans = min(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}