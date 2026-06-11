#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	vector<vector<int>> a(3, vector<int>(3));
	rep(i, 3)rep(t, 3)
	{
		cin >> a[i][t];
	}
	int n;
	cin >> n;
	vector<int> b(n);
	rep(i, n) cin >> b[i];

	vector<vector<bool>> c(3, vector<bool>(3,false));
	rep(i, n)
	{
		rep(p, 3)rep(q, 3)
		{
			if (b[i] == a[p][q])
			{
				c[p][q] = true;
			}
		}
	}

	bool ans = false;
	bool tfa,tfb;
	rep(x, 3)
	{
		tfa = true;
		tfb = true;
		rep(y, 3)
		{
			tfa &= c[x][y];
			tfb &= c[y][x];
		}
		if (tfa || tfb)
		{
			ans = true;
		}

	}

	if (c[0][0] && c[1][1] && c[2][2]) ans = true;
	if (c[0][2] && c[1][1] && c[2][0]) ans = true;

	if (ans)cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}