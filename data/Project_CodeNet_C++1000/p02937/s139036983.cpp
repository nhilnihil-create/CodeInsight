#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	string s, t; cin >> s >> t;
	ll N = s.size();
	ll M = t.size();

	vector<ll> cnts(26, 0), cntt(26, 0);
	for (auto &c : s)
	{
		++cnts[c-'a'];
	}
	for (auto &c : t)
	{
		++cntt[c-'a'];
	}


	ll res{-1};
	REP(i, 26)
	{
		if (cntt[i])
		{
			if (cnts[i] == 0)
			{
				std::cout << res << std::endl;
				return 0;
			}
		}
	}

	map<char, vector<ll>> V;
	REP(i, N)
	{
		V[s[i]].push_back(i);
	}

	ll times{0};
	ll k;
	for (ll i = 0; i < M;)
	{
		char c = t[i];
		k = V[c].front();
		ll j = i + 1;
		while (j < M)
		{
			if (V[t[j]].back() <= k)
				break;

			k = *upper_bound(V[t[j]].begin(), V[t[j]].end(), k);
			++j;
		}

		if (j >= M)
		{
			res = k;
			break;
		}
		else
			++times;

		i = j;
	}


	std::cout << N*times + res + 1<< std::endl;
	// std::cout << "times : " << times << std::endl;
	// std::cout << "res : " << res << std::endl;
}