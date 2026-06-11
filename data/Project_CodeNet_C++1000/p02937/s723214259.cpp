#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> v[33];
string s, t;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll i, next = 0, cnt = 0;

	cin >> s >> t;

	for (i = 0; i < s.size(); i++)
		v[s[i] - 'a'].push_back(i);

	for (i = 0; i < t.size(); i++)
	{
		ll what = t[i] - 'a';

		if (v[what].empty())
		{
			cout << -1;
			return 0;
		}

		int point = lower_bound(v[what].begin(), v[what].end(), next) - v[what].begin();

		if (point == v[what].size())
		{
			++cnt;
			next = v[what][0] + 1;
		}
		else
			next = v[what][point] + 1;
	}

	cout << cnt * (ll)s.size() + next;
	return 0;
}