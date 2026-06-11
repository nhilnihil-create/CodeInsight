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
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;
#define DEBUG(x) ;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N; cin >> N;
	vector<ll> tmp;
	while (N > 0)
	{
		ll t = N%26;
		if (t == 0) tmp.push_back(25);
		else tmp.push_back(t-1);

		if (N <= 26) break;

		N /= 26;
		if (t == 0) --N;
	}

	reverse(ALL(tmp));
	for (auto &nv : tmp)
	{
		std::cout << char('a' + nv);
	}
}
