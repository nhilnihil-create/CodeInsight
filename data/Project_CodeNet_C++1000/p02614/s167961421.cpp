#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int main()
{
	int H, W, K;
	cin >> H >> W >> K;
	
	vector<string> grid(H);
	for (int h = 0; h < H; h++)
		cin >> grid[h];

	int count = 0;
	for (int i = 0; i < (1 << H+W); i++)
	{
		vector<string> temp(grid);
		for (int n = 0; n < H+W; n++)
			if ((i >> n) & 1)
			{
				if (n < H)
					for (int c = 0; c < W; c++)
						temp[n][c] = 'R';
				else
					for (int r = 0; r < H; r++)
						temp[r][n-H] = 'R';
			}
		int blacks = 0;
		for (int r = 0; r < H; r++)
			for (int c = 0; c < W; c++)
				if (temp[r][c] == '#')
					blacks++;
		if (blacks == K)
			count += 1;
	}
	cout << count << endl;
}

