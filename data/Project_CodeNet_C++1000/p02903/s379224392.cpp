#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	int s[h][w];
	rep(i, h)
	{
		rep(j, w)
		{
			if (i < b && j < a)
				s[i][j] = 0;
			else if (i < b)
				s[i][j] = 1;
			else if (j < a)
				s[i][j] = 1;
			else
				s[i][j] = 0;
		}
	}
	rep(i, h) 
	{
		rep(j, w)
			cout << s[i][j];
		cout << '\n';
	}
	return 0;
}
