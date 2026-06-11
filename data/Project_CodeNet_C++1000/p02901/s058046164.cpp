#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1010, M = 1 << 12, INF = 0x3f3f3f3f;

int n, m;
int a[N], b[N];
int f[N][M];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
	{
		int k;
		cin >> a[i] >> k;
		for (int j = 0; j < k; j ++ )
		{
			int t;
			cin >> t;
			b[i] += 1 << (t - 1);
		}
	}
	
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= m; i ++ )
	{
		memcpy(f[i], f[i - 1], sizeof f[i]);
		for (int j = 0; j < 1 << n; j ++ )
		{
			int &t = f[i][j | b[i]];
			t = min(t, min(f[i - 1][j | b[i]], f[i - 1][j] + a[i]));
		}
	}
		
	int res = f[m][(1 << n) - 1];
	if (res == INF) puts("-1");
	else cout << res << endl;
	return 0;
}