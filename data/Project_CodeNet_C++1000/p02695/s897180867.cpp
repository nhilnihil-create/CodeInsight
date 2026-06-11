#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 55;
int n, m, q, a[M], b[M], c[M], d[M];

void solve(int i, vector <int> &v, int &ans)
{
	if(i > n)
	{
		int cur = 0;
		for(int j = 0; j < q; j++)
			if(v[b[j]] - v[a[j]] == c[j])
				cur += d[j];
		ans = max(ans, cur);
		return;
	}
	for(int j = v[i - 1]; j <= m; j++)
	{
		v[i] = j;
		solve(i + 1, v, ans);
	}
}

int32_t main() 
{
	ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < q; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector <int> v(n + 1, 1);
	int ans = 0;
	solve(1, v, ans);
	cout << ans;
    	return 0;
}