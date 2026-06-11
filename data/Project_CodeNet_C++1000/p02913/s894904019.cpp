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

vector<ll> zAlgorithm(const string& s)
{
	ll N = (ll)s.size();
	vector<ll> res(N);

	for (ll i = 1, j = 0; i < N;)
	{
		while (i + j < N && s[j] == s[i+j]) ++j;
		res[i] = j;
		if (j == 0) {++i; continue;}
		ll k{1};
		while (i+k < N && k+res[k] < j) res[i+k] = res[k], ++k;
		i += k;
		j -= k;
	}

	res[0] = N;
	return res;
}


int main(int argc, char **argv)
{
	ll N; cin >> N;
	string S; cin >> S;

	ll res{0};
	
	REP(i, N)
	{
		vector<ll> z = zAlgorithm(S.substr(i, N-i));
		ll sz = z.size();
		for (ll j = 1; j < sz; ++j)
			if (j >= z[j]) res = max(res, z[j]);
	}

	std::cout << res << std::endl;
}
