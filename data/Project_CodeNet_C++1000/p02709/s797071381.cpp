#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

#define eps 1e-12
#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define bgn begin
#define ll long long
#define ld long double
#define ull unsigned long long
#define ii pair<ll,ll>









const int N = 2010;
ll n, dp[N][N];
ii p[N];




void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i].st;
		p[i].nd = i;
	}
	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	for(int j = 0; j < n + 1; j++)
	{
		dp[n + 1][j] = 0;
	}
	for(int i = n; i >= 1; i--)
	{
		for(int j = 0; j < i; j++)
		{
			dp[i][j] = max(dp[i + 1][j + 1] + p[i].st*(p[i].nd - j - 1), dp[i + 1][j] + p[i].st*(n - i + j + 1 - p[i].nd));
		}
	}
	cout << dp[1][0] << "\n";
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef localProject
	freopen("in.txt","r",stdin);
#endif
	solve();
	return 0;
}