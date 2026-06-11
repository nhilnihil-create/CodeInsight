#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 3010, M = 1010;

int n, m;
int v[N], w[N];
int f[N][N], g[N][N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j <= m; j ++ )
		{
			f[i][j] = f[i - 1][j];
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
		
	for (int i = n; i >= 1; i -- )
		for (int j = 0; j <= m; j ++ )
		{
			g[i][j] = g[i + 1][j];
			if (j >= v[i]) g[i][j] = max(g[i][j], g[i + 1][j - v[i]] + w[i]);
		}
		
	int res = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < m; j ++ )
			res = max(res, w[i] + f[i - 1][j] + g[i + 1][m - j - 1]);
			
	cout << res << endl;
    return 0;
}