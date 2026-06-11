#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	map<ll, ll> m;
	for (ll i = 0; i < N; ++i)
	{
		ll a; cin >> a;
		if (a == 0 && i != 0)
		{
			std::cout << 0 << std::endl;
			return 0;
		}
		++m[a];
	}

	if (m[0] != 1)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		ll res{1};
		for (auto &p : m)
		{
			for (ll i = 0; i < p.second; ++i)
			{
				if (p.first == 0) continue;
				(res *= m[p.first-1]) %= MOD;
			}
		}

		std::cout << res << std::endl;
	}
}
