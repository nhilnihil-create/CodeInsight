#pragma GCC optimize(2)
#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include<cstring>
#include <stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include <string>
#define itn int
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int t, n, m, T;
const int maxn = 2000+6;//点数
const int MAXM = 3e5+6;//边数
struct node {
	int i;
	int a;
};
ll dp[maxn][maxn];
int main()
{
#ifdef _DEBUG
	freopen("D:\\input.txt", "r", stdin);
	//	freopen("E:\\output.txt", "w", stdout);
#endif
	int i, j,len;
	std::ios::sync_with_stdio(false); cin.tie(0);	cout.tie(0);
	cin >> n;
	vector<node>a(n+1);
    for (int i = 1; i <= n; i++) {
		cin >> a[i].a;
		a[i].i = i;
	}
	sort(a.begin()+1, a.end(), [](const node& x, const node& y) {
		return x.a < y.a;
		});
	for (int i = 1; i <= n; i++) {
		dp[i][i] = (ll)a[1].a * abs(a[1].i - i);
	}
	for (len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			j = i + len - 1;
			dp[i][j] = max(dp[i + 1][j] + (ll)a[len].a*abs(a[len].i - i),
				dp[i][j - 1] + (ll)a[len].a * abs(a[len].i - j));
		}
	}
	cout << dp[1][n]<<"\n";
	return 0;
}