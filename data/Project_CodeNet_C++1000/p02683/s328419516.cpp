#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	vector<int> c(n);
	vector<vector<int>> a(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		cin >> c[i];

		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int min = (int)1e8;

	for (int i = 0; i < (1<<n); i++)
	{
		int price = 0;
		vector<int> sum(m, 0);

		for (int j = 0; j < n; j++)
		{
			if (i & (1<<j))
			{
				price += c[j];

				for (int k = 0; k < m; k++)
				{
					sum[k] += a[j][k];
				}
			}
		}

		int flg = 1;

		for (int k = 0; k < m; k++)
		{
			if (sum[k] < x) flg = 0;
		}

		if (flg)
		{
			if (min > price) min = price;
		}
	}

	if (min == (int)1e8) cout << -1 << endl;
	else cout << min << endl;

	return 0;
}