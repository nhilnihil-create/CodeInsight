#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll n, m; cin >> n >> m;
	vector<ll> a(n), b(n);
	REP(i, n) cin >> a[i] >> b[i];

	map<ll, vector<ll>> ma;
	REP(i, n)
		ma[m-a[i]].emplace_back(b[i]);

	ll res{0};
	priority_queue<ll> que;
	for (ll i = m-1; i >= 0; --i)
	{
		for (auto &e : ma[i]) que.push(e);
		if (que.size())
		{
			res += que.top();
			que.pop();
		}
	}

	std::cout << res << std::endl;
}
