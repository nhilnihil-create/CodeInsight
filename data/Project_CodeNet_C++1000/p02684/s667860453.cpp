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
#define DEBUG(x) ;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, K; cin >> N >> K;
	vector<ll> A(N); REP(i, N) cin >> A[i], --A[i];
	DEBUG("pass23");

	ll logK{0};
	while ((1ll << logK) < K) ++logK;

	DEBUG("pass10");

	vector<vector<ll>> ding(logK, vector<ll>(N));
	REP(i, N)
		ding[0][i] = A[i];

	DEBUG("pass100");
	

	REP(k, logK-1)
	{
		REP(i, N)
		{
			DEBUG("pass2");
			// ll ne = ding[k][i];
			// ll ne2 = ding[k][ne];
			// ding[k+1][i] = ne2;
			ding[k+1][i] = ding[k][ding[k][i]];
		}
	}

	DEBUG("pass");
	ll now{0};
	for (ll bit = 0; ;++bit)
	{
		if (K & 1) now = ding[bit][now];
		K = K >> 1;
		if (K == 0) break;
	}

	std::cout << now + 1<< std::endl;
	return 0;
}
