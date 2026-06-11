#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n); rep(i, n)cin >> a[i];
	vector<int> p(1001001);
	for (int i = 2; i <= 1000000; ++i)
	{
		if (p[i])continue;
		for (int j = i; j <= 1000000; j += i)
		{
			if (p[j])continue;
			p[j] = i;
		}
	}
	vector<bool> used(1001001);
	bool pairwise = true;
	rep(i, n)
	{
		int now = a[i];
		while (now > 1)
		{
			int d = p[now];
			if (used[d])pairwise = false;
			used[d] = true;
			while (p[now] == d)
			{
				now /= d;
			}
		}
	}
	if (pairwise)
	{
		cout << "pairwise coprime" << endl;
		return 0;
	}
	int g = 0;
	rep(i, n)g = gcd(a[i], g);
	if (g == 1)cout << "setwise coprime" << endl;
	else cout << "not coprime" << endl;
}