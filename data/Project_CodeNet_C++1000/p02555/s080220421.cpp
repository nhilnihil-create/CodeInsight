#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll dp[2010];
int s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> s;
    for(int i = 3; i <= 2000; i++) dp[i] = 1;
    for(int i = 1; i <= s; i++)
    {
    	for(int j = 3; j <= i; j++)
    	{
    		dp[i] += dp[i - j];
    		dp[i] %= mod;
		}
	}
	cout << dp[s] << endl;
	return 0;
}
