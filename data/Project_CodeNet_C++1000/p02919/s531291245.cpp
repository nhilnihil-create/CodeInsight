#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
set <int> s;
int pos[102020];
int n;
int ans;
int32_t main()
{
	usecppio
	cin >> n;
	for (int i = 1; i<=n; i++)
	{
		int x;
		cin >> x;
		pos[x] = i;
	}
	s.insert(0);
	s.insert(n+1);
	for (int i = n; i>0; i--)
	{
		s.insert(pos[i]);
		auto p = s.find(pos[i]);
		auto l = p; l--;
		auto r = p; r++;
		int pp = *p;
		int lp = *l, rp = *r;
		if (lp)
		{
			l--;
			int lp2 = *l;
			ans += (i) * (lp-lp2) * (rp - pp);
		}
		if (rp <= n)
		{
			r++;
			int rp2 = *r;
			ans += (i) * (rp2-rp) * (pp-lp);
		}
	}
	cout << ans << '\n';
}