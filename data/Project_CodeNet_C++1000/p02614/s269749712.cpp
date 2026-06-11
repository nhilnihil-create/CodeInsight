#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<math.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int h, w, k;
	cin >> h >> w >> k;
	vector<vector<char>> cc(h, vector<char>(w));
	rep(i, h)rep(t, w) cin >> cc[i][t];
	vector<vector<char>> c(h, vector<char>(w));
	int ans = 0;

	for (int biti = 0; biti < (1<<h); biti++)
	{
		for (int bitt = 0; bitt < (1<<w); bitt++)
		{
			rep(ii, h)rep(tt, w) c[ii][tt] = cc[ii][tt];

			for (int i = 0; i < h; i++)
			{
				if (biti & (1 << i))
				{
					for (int x=0; x < w; x++)
					{
						c[i][x] = '?';
					}
				}
			}
			
			for (int t = 0; t < w; t++)
			{
				if (bitt & (1 << t))
				{
					for (int y = 0; y < h; y++)
					{
						c[y][t] = '*';
					}
				}
			}
			          
			int count = 0;
			rep(p, h)rep(q, w)
			{
				if (c[p][q] == '#') count++;
			}
			if (count == k) ans++;
		}
	}

	cout << ans;	
	return 0;
}