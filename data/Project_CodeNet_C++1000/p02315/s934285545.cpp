#include<cstring>
#include<climits>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10500;
int dp[maxn], v[maxn], w[maxn];
int main()
{
		memset(dp, 0, sizeof(dp));
		int n, W; cin >> n >> W;
		for (int i = 1; i<=n; i++) cin >> v[i]>>w[i];
		for (int i = 1; i<=n; i++)
			for (int j = W; j >= w[i]; j--)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		cout << dp[W] << endl;
}