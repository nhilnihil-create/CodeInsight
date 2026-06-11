#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll solve(void)
{
	ll n, m;
	cin >> n >> m;

	map<ll, vll> mp;

	for (ll i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}

	priority_queue<ll> q;
	ll ans = 0;
	for (ll i = 1; i <= m; i++)
	{
		for (auto a: mp[i])
			q.push(a);
		if (q.empty()) { continue; }
		ans += q.top();
		q.pop();
	}

	cout << ans << endl;

	return 0;
}

int main(void)
{
	// 追加２, 以降 cin の入力元が 'input.txt' になる
	// std::ifstream in("data.txt");
	// std::cin.rdbuf(in.rdbuf());

	while(solve()){}

	return 0;
}