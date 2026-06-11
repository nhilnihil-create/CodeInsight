#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 3010, M = 3010;

int n, m;
int a[N], b[N];
int f1[N][N], f2[N][N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i] >> b[i];
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < m; j ++ )
		{
			f1[i][j] = max(f1[i][j], f1[i - 1][j]);
			if (j >= a[i]) f1[i][j] = max(f1[i][j], f1[i - 1][j - a[i]] + b[i]);
		}
	
	for (int i = n; i >= 1; i -- )
		for (int j = 0; j < m; j ++ )
		{
			f2[i][j] = max(f2[i][j], f2[i + 1][j]);
			if (j >= a[i]) f2[i][j] = max(f2[i][j], f2[i + 1][j - a[i]] + b[i]);
		}
	
	int res = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < m; j ++ ) 
			res = max(res, b[i] + f1[i - 1][j] + f2[i + 1][m - 1 - j]);
	
	cout << res << endl;
	return 0;
}