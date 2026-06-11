#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n;
	cin >> n;
	vector<int64_t> as(n);
	for (auto &&a : as)
	{
		cin >> a;
	}

	bool s = [&] {
		int64_t g = 0;
		for (auto &&a : as)
		{
			g = gcd(g, a);
		}
		return (g == 1);
	}();

	bool p = [&] {
		vector<int64_t> d(1000001, -1);
		for (int64_t i = 2; i <= 1000; i++)
		{
			if (d[i] == -1)
			{
				for (int64_t j = i; j <= 1000000; j += i)
				{
					d[j] = i;
				}
			}
		}
		for (int64_t i = 1000; i <= 1000000; i++)
		{
			if (d[i] == -1)
			{
				d[i] = i;
			}
		}

		vector<set<int64_t>> v(n);
		for (int64_t i = 0; i < n; i++)
		{
			while (as[i] != 1)
			{
				v[i].insert(d[as[i]]);
				as[i] /= d[as[i]];
			}
		}

		set<int64_t> st;
		for (auto &&xs : v)
		{
			for (auto &&x : xs)
			{
				if (st.find(x) != st.end())
				{
					return false;
				}

				st.insert(x);
			}
		}

		return true;
	}();

	if (p)
	{
		cout << "pairwise coprime" << endl;
	}
	else if (s)
	{
		cout << "setwise coprime" << endl;
	}
	else
	{
		cout << "not coprime" << endl;
	}

	return 0;
}