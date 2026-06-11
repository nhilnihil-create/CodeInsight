#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int H, W, K;
	cin >> H >> W >> K;
	vector<string> c(H);
	for (int i = 0; i < H; ++i) cin >> c[i];


	int ans = 0;
	for (int ic = 0; ic < 1 << H; ++ic)
	{
		for (int jc = 0; jc < 1 << W; ++jc)
		{
			int cnt = 0;
			for (int i = 0; i < H; ++i)
			{
				for (int j = 0; j < W; ++j)
				{
					if (ic >> i & 1) continue;
					if (jc >> j & 1) continue;
					if (c[i][j] == '#') ++cnt;
				}
			}
			if (cnt == K) ans++;
		}
	}
	cout << ans << endl;
}		