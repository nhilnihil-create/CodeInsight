#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int n, m, q;
vv(int) V(4, vector<int>(50));

vector<int> A(10);
int ans;

void	dfs(int id, int pre)
{
	if (id == n)
	{
		int now = 0;
		for (int i = 0; i < q; ++i)
			if (A[V[1][i]-1] - A[V[0][i]-1] == V[2][i])
				now += V[3][i];
		ans = max(ans, now);
	}
	else
	{
		for (int i = pre; i <= m; ++i)
		{
			A[id] = i;
			dfs(id+1, i);
		}
	}
}

int		main(void)
{
	cin >> n >> m >> q;

	for (int i = 0; i < q; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		V[0][i] = a;
		V[1][i] = b;
		V[2][i] = c;
		V[3][i] = d;
	}
	dfs(0, 1);
	cout << ans << endl;
}

