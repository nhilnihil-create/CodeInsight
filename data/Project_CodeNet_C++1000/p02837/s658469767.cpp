#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	vector<vector<int>> x, y;
	rep(i, N)
	{
		cin >> A[i];

		x.push_back(vector<int>(A[i]));
		y.push_back(vector<int>(A[i]));
		rep(j, A[i])
		{
			cin >> x[i][j] >> y[i][j];
			--x[i][j];
		}
	}

	int iter_num = 1 << N;
	int ans = 0;
	rep(i, iter_num)
	{
		vector<int> a(N, 0);
		int m = i;
		int count = 0;
		for (int j = 0; m != 0; ++j)
		{
			if ((m & 0x1) == 1)
			{
				a[j] = 1;
				++count;
			}
			m >>= 1;
		}

		if (count <= ans) continue;

		bool isOk = true;
		rep(j, N)
		{
			if (a[j] == 1)
			{
				rep(k, A[j])
				{
					if (a[x[j][k]] != y[j][k])
					{
						isOk = false;
						break;
					}
				}

				if (!isOk)
				{
					break;
				}
			}
		}

		if (isOk) ans = count;
	}

	cout << ans << endl;
}