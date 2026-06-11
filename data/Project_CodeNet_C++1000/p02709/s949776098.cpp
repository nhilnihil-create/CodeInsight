#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<stack>
#include<sstream>
//#include <Eigen/Dense>
//#include <Eigen/Geometry>
//using namespace Eigen;
using namespace std;

const int maxn = 2005;
int a[maxn];
int p[maxn];
long long dp[maxn][maxn];
int n;
long long dfs(int start,int end,int cur)
{
	if (start > end || end < start)
		return 0;
	if (dp[start][end] != 0)
		return dp[start][end];
	long long cost1 = 1LL*a[p[cur]] * abs(p[cur] - start) + dfs(start + 1, end, cur + 1);
	long long cost2 = 1LL*a[p[cur]] * abs(p[cur] - end) + dfs(start, end - 1, cur + 1);

	dp[start][end] = max(cost1, cost2);
	return dp[start][end];
}
int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		p[i] = i;
	sort(p, p + n, [&](int i, int j) {return a[i] > a[j]; });

	cout << dfs(0, n - 1, 0) << endl;
	

	return 0;
}
