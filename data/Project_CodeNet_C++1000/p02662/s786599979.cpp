#ifdef MY_LOCAL
#define MY_NAMESPACE(ns) namespace ns {
#define MY_NAMESPACE_    }
#define MY_DEBUG(s)      s
#else
#define MY_NAMESPACE(ns) 
#define MY_NAMESPACE_    
#define MY_DEBUG(s)      
#endif

#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define EPS (1e-7)

MY_NAMESPACE(ABC169F)
int main()
{
	const int modval = 998244353;

	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<vector<ll>> dp(n + 1, vector<ll>(s + 1));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			dp[i + 1][j] = dp[i][j] * 2 % modval;
			if (j - a[i] >= 0)
			{
				dp[i + 1][j] += dp[i][j - a[i]];
				dp[i + 1][j] %= modval;
			}
		}
	}
	cout << dp[n][s] << "\n";
	return 0;
}
MY_NAMESPACE_