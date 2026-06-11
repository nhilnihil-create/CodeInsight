#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m, k, s;
	cin >> n >> k >> s;
	vector<int> v;
	rep(i, k)
	{
		v.push_back(s);
	}
	if (s < 1000000000)
	{
		rep(i, n - k)
			v.push_back(s + 1);
	}
	else
	{
		rep(i, n - k)
			v.push_back(1);
	}
	rep(i, v.size()) printf("%d%c", v[i], i==v.size()-1?' ':'\n');
	return 0;
}
