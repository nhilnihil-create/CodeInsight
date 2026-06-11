#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	vector<vector<int>> x(n, vector<int>(d));
	rep(i, n)
	{
		rep(j, d)
		{
			scanf("%d", &x[i][j]);
		}
	}

	int ans = 0;
	rep(i, n)
	{
		for (int j = i + 1; j < n; j++) //重複しないようにi+1
		{
			int norm = 0;
			for (int k = 0; k < d; k++)
			{
				int diff = abs(x[i][k] - x[j][k]);
				norm += diff * diff;
			}
			
			bool flag = false;
			for (int k = 0; k <= norm; k++)
			{
				if (k * k == norm)
				{
					flag = true;
				}
			}
			if (flag) ans++;
		}
	}
	cout << ans << endl;
}