#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;

signed main(void)
{
	int n; 
	cin >> n;
	long long ans, tmp;
	vector<int> a(n);
	vector<P> out;
	bool plus[n];

	rep(i, n) cin >> a[i];
	sort(a.rbegin(), a.rend());	
	plus[0] = true;
	plus[n - 1] = false;
	for(int i = 1; i < n - 1; i++)
	{
		if (a[i] < 0)
			plus[i] = false;
		else
			plus[i] = true;
	}

	ans = a[0];
	tmp = a[n - 1];
	for(int i = n - 2; i >= 1; i--)
	{
		if (plus[i])
		{
			out.push_back(P(tmp, a[i]));
			tmp -= a[i];
		}
	}
	for(int i = 1; i < n - 1; i++)
	{
		if (!plus[i])
		{
			out.push_back(P(ans, a[i]));
			ans -= a[i];
		}
	}
	out.push_back(P(ans, tmp));
	ans -= tmp;
	cout << ans << endl;
	rep(i, out.size()) 
		printf("%d%c%d%c", out[i].first, ' ', out[i].second, '\n');
	return 0;
}
