#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n;
	cin >> n;

	vv(int) A(15, vector<int>(15, -1));
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int x, y;
			cin >> x >> y;
			x--;
			A[i][x] = y;
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		bitset<15> man(i);
		vector<int> check(n, -1);
		bool f = true;
		for (int j = 0; j < n; j++)
		{
			if (man[j])
			{
				for (int k = 0; k < n; k++)
				{
					if (A[j][k] == -1)
						continue ;
					else if (check[k] == -1)
						check[k] = A[j][k];
					else if (check[k] != A[j][k])
						f = false;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (man[j] != check[j] && check[j] != -1)
				f = false;
		}
		if (f)
			ans = max(ans, (int)man.count());
	}
	cout << ans << endl;
}

