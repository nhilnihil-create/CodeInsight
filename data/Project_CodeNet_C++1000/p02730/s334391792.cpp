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
	string s;
	cin >> s;
	bool ans = true;
	ll n;
	n = s.size();
	string rs;
	rs = s;
	reverse(rs.begin(), rs.end());
	rep(i, n)
	{
		if (s[i] != rs[i])
		{
			ans = false;
		}
	}
	string a, b;
	rep(i, (n - 1) / 2)
	{
		a.push_back(s[i]);
		b.push_back(s[i + (n + 1) / 2]);
	}

	string ra, rb;
	ra = a;
	reverse(ra.begin(), ra.end());
	rb = b;
	reverse(rb.begin(), rb.end());
	rep(i, a.size())
	{
		if (a[i] != ra[i]||b[i]!=rb[i])
		{
			ans = false;
		}
	}

	if (ans) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}