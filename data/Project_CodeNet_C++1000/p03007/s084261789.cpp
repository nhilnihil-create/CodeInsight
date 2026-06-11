#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	vector<ll> p;
	vector<ll> m;
	for (auto i = 0; i < N; ++i)
	{
		ll A;
		cin >> A;
		if (A > 0)
		{
			p.push_back(A);
		}
		else
		{
			m.push_back(A);
		}
	}
	sort(p.begin(), p.end(), greater<ll>());
	sort(m.begin(), m.end(), greater<ll>());

	auto ans = 0ll;
	vector<pair<ll, ll>> list;
	if (p.size() > 0)
	{
		if (m.size() > 0)
		{
			auto prev = m[0];
			for (auto i = 1; i < (int)p.size(); ++i)
			{
				list.push_back({ prev, p[i] });
				prev -= p[i];
			}

			list.push_back({ p[0], prev });
			prev = p[0] - prev;

			for (auto i = 1; i < (int)m.size(); ++i)
			{
				list.push_back({ prev, m[i] });
				prev -= m[i];
			}
			ans = prev;
		}
		else
		{
			auto prev = p[(int)p.size() - 1];
			for (auto i = (int)p.size() - 2; i > 0; --i)
			{
				list.push_back({ prev, p[i] });
				prev -= p[i];
			}
			list.push_back({ p[0], prev });
			ans = p[0] - prev;
		}
	}
	else
	{
		auto prev = m[0];
		for (auto i = 0; i < (int)m.size() - 1; ++i)
		{
			list.push_back({ prev, m[i + 1] });
			prev -= m[i + 1];
		}
		ans = prev;
	}

	cout << ans << endl;
	for (auto i = 0; i < (int)list.size(); ++i)
	{
		cout << list[i].first << " " << list[i].second << endl;
	}

	return 0;
}