#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

#define ll long long
#define pll pair<ll, ll>

#define reps(i, f, n) for (int i = (f); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

const int INF = 1111111111;

using namespace std;

const int H = 111;
const int W = 111;

int h, w;
char b[H][W];

void init()
{
	cin >> h >> w;
	reps(i, 1, h + 1)
	{
		reps(j, 1, w + 1)
		{
			cin >> b[i][j];
		}
	}

	rep(i, H)
	{
		b[i][0] = b[0][i] = '*';
	}
}

int v[H][W];

void solve()
{
	rep(i, H) rep(j, W) v[i][j] = INF;
	v[1][1] = 0;

	reps(i, 1, h + 1)
	{
		reps(j, 1, w + 1)
		{
			v[i][j] = min(v[i][j], v[i - 1][j] + 1);
			v[i][j] = min(v[i][j], v[i][j - 1] + 1);

			if (b[i][j] != b[i - 1][j])
			{
				if (b[i - 1][j] == '#')
				{
					v[i][j] = min(v[i][j], v[i - 1][j]);
				}
			}
			if (b[i][j] != b[i][j - 1])
			{
				if (b[i][j - 1] == '#')
				{
					v[i][j] = min(v[i][j], v[i][j - 1]);
				}
			}
			if (b[i][j] == b[i - 1][j])
			{
				v[i][j] = min(v[i][j], v[i - 1][j]);
			}
			if (b[i][j] == b[i][j - 1])
			{
				v[i][j] = min(v[i][j], v[i][j - 1]);
			}
		}
	}

	int add = b[1][1] == '#' ? 1 : 0;
	cout << v[h][w] + add << endl;
}

int main()
{
	init();
	solve();
}
