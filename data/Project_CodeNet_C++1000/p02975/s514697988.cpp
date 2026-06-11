#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	int n, x[3], cnt_0;
	cin >> n;
	vector<int> a(n);
	map<ll, ll> mp;
	bool ok;

	cnt_0 = 0;
	rep(i, n) 
	{
		cin >> a[i];
		if (a[i] == 0)
			cnt_0++;
		mp[a[i]]++;
	}
	if (cnt_0 == n)
		ok = true;
	else if (n % 3 == 0)
	{
		if (cnt_0 == n / 3 && mp.size() == 2)
			ok = true;
		else
		{
			if (mp.size() == 3)
			{
				ok = true;
				int i = 0;
				for(auto p : mp)
				{
					x[i++] = p.first;
					if (p.second != n / 3)
						ok = false;
				}
				if (ok && (!((x[0] ^ x[1] ^ x[2] )== 0)))
					ok = false;
			}
			else
				ok = false;
		}
	}
	else
		ok = false;
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
