#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
int ans[5050];
/*void dfs(int x)
{
	if (x >= 3) {ans = ((ans % mod) + 1) % mod;}
	for (int i = 3; i <= x; ++i)
		dfs(x - i);
}*/
int main()
{
	/*for (int i = 1; i <= 2000; ++i)
	{
		ans = 0;
		dfs(i);
		cout << ans << ", ";
	}*/
	int s;
	cin >> s;
	ans[1] = 0;
	ans[2] = 0;
	ans[3] = 1;
	if (s <= 3) cout << ans[s];
	else
	{
		for (int i = 4; i <= s; ++i)
			ans[i] = (ans[i - 1] + ans[i - 3]) % mod;
		cout << ans[s] << " ";
	}
	return 0;
}
