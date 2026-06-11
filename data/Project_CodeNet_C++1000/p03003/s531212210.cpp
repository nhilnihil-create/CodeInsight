#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int a[N];
int b[N];
LL dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	dp[n][m] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			if (a[i] == b[j]) dp[i][j] += 1 + dp[i - 1][j - 1];
			while (dp[i][j] >= INF) dp[i][j] -= INF;
			if (dp[i][j] < 0) dp[i][j] += INF;
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}