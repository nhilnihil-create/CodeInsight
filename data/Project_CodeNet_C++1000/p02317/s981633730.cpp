#include <bits/stdc++.h>

#define INF 200000000
#define FER 0.0000000001

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;

int dp[100001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	fill(dp, dp + 100001, INT_MAX);

	int n;

	cin >> n;

	int a;
	int length = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (dp[length - 1] < a)
		{
			dp[length++] = a;
		}
		else
		{
			(*lower_bound(dp, dp + length, a)) = a;
		}
	}

	cout << length << endl;
	
	return 0;
}
