#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

const int INF = 1000000000;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	vector<int> b(m);
	int c[1007][12];
	for (int i = 0; i < m; ++i) 
	{
		cin >> a[i] >> b[i];
		for (int j = 0; j < b[i]; ++j)
		{
			cin >> c[i][j];
			--c[i][j];
		}
	}

    vector<int> dp(5000, INF);
    dp[0] = 0;
    for(int i = 0; i < m; i++)
	{
        int now = 0;
        for(int j = 0; j < b[i]; j++)
		{
            now |= (1 << (c[i][j]));
        }
        for(int mask = 0; mask < (1 << n); mask++)
		{
            dp[mask | now] = min(dp[mask | now], dp[mask] + a[i]);
        }
    }
    cout << (dp[(1 << n) - 1] == INF ? -1 : dp[(1 << n) - 1]);

}

int main()
{
	fastio;
	solve();

	return 0;
}