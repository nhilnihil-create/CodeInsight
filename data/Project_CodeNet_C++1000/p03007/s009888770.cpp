#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N); REP(i, N) cin >> A[i];
	sort(ALL(A));

	vector<pair<ll, ll>> res;
	vector<ll> plus, minus;
	for (auto &e : A)
	{
		if (e < 0) minus.push_back(e);
		else if (e > 0) plus.push_back(e);
		else
		{
			if (A.front() >= 0)
			{
				minus.push_back(0);
			}
			else
			{
				plus.push_back(0);
			}
		}
	}

	sort(ALL(minus)); // -3, -2, -1
	sort(ALL(plus), greater<ll>()); // 3, 2, 1

	if (plus.empty())
	{
		ll m1 = minus.back();
		minus.pop_back();
		ll m2 = minus.back();
		minus.pop_back();

		res.emplace_back(pair<ll, ll>(m2, m1));
		plus.push_back(m2 - m1);
	}
	else if (minus.empty())
	{
		ll p1 = plus.back();
		plus.pop_back();
		ll p2 = plus.back();
		plus.pop_back();

		res.emplace_back(pair<ll, ll>(p1, p2));
		minus.push_back(p1 - p2);
	}

	while (plus.size() != 1)
	{
		ll p = plus.back();
		plus.pop_back();
		ll m = minus.back();
		minus.pop_back();

		res.emplace_back(pair<ll, ll>(m, p));
		minus.push_back(m-p);
	}

	ll resM{-INF};
	while (!minus.empty())
	{
		ll m = minus.back();
		ll p = plus.back();
		minus.pop_back();
		plus.pop_back();

		res.emplace_back(pair<ll, ll>(p, m));
		resM = max(resM, p-m);
		plus.push_back(p-m);
	}

	std::cout << resM<< std::endl;
	for (auto &e : res)
	{
		std::cout << e.first << " " << e.second << std::endl;
	}
}
