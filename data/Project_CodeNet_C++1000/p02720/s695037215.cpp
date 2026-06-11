#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll solve(void)
{
	ll k;
	cin >> k;

	queue<ll> q;
	for (ll i = 1; i <= 9; i++)
		q.push(i);

	ll cnt = 0;
	while (++cnt < k)
	{
		auto f = q.front();
		auto g = f % 10;
		auto h = f * 10;

		if (g > 0) { q.push(h + g - 1); }
		q.push(h + g);
		if (g < 9) { q.push(h + g + 1); }

		q.pop();
	}

	cout << q.front() << endl;

	return 0;
}

int main(void)
{
	while(solve()){}

	return 0;
}