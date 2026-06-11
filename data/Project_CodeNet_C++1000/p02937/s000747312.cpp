#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> v[27];
string s, t;

int main(void)
{
	ll i, nxt = 0, it, cnt = 0;

	cin >> s >> t;

	for (i = 0; i < s.size(); i++)
		v[s[i] - 'a'].push_back(i);

	for (i = 0; i < t.size(); i++)
	{
		ll sh = t[i] - 'a';

		if (v[sh].empty())
		{
			cout << -1;
			return 0;
		}

		it = lower_bound(v[sh].begin(), v[sh].end(), nxt) - v[sh].begin();
		if (it == v[sh].size())
		{
			++cnt;
			nxt = v[sh][0] + 1;
		}
		else
			nxt = v[sh][it] + 1;
	}

	cout << cnt * (ll)s.size() + nxt;
	return 0;
}
