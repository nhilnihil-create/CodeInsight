#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

bool b[100010];
ll dp[100010];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		b[a] = true;
	}
	dp[0] = 1;
	if (b[1]) dp[1] = 0;
	else dp[1] = 1;
	if (b[2]) dp[2] = 0;
	else dp[2] = dp[0] + dp[1];
	for (int i = 3; i <= N; i++) {
		if (b[i]) dp[i] = 0;
		else dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
	}
	cout << dp[N] << endl;
}