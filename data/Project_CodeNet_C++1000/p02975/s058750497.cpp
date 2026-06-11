#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	map<ll, ll> m;
	for (ll i = 0; i < N; ++i)
	{
		ll a; cin >> a;
		++m[a];
	}

	string res{"No"};
	if (N%3==0)
	{
		if (m.size() == 1)
		{
			if (m.count(0) && m[0])
				res = "Yes";
		}
		else if (m.size() == 2)
		{
			if (m.count(0) && ((ll)m[0] == N/3))
			{
				res = "Yes";
			}
		}
		else if (m.size() == 3)
		{
			bool ok{true};
			ll tmp{0};
			for (auto &p : m)
			{
				tmp ^= p.first;
				if (p.second*3 != N)
					ok = false;
			}
			if (ok && !tmp)
				res = "Yes";
		}
	}
	else
	{
		if ((m.size() == 1) && m.count(0))
			res = "Yes";
	}
	std::cout << res << std::endl;
}
