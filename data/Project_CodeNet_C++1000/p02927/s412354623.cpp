#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int m, d; cin >> m >> d;
	int res = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 22; j <= d; ++j)
		{
			int d10 = j / 10;
			int d1 = j % 10;
			if (d1 < 2)continue;
			if (d1*d10 == i)++res;
		}
	}
	cout << res << endl;
}