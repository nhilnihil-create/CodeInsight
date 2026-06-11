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

ll N, K;
vector<ll> A, F;


int main(int argc, char **argv)
{
	cin >> N >> K;
	A.resize(N);
	F.resize(N);
	REP(i, N) cin >> A[i];
	REP(i, N) cin >> F[i];

	sort(ALL(A));
	sort(ALL(F), greater<ll>());

	auto isok =
		[&](ll x) -> bool
		{
			ll cnt{0};
			REP(i, N)
			{
				ll tmp = x / F[i];
				cnt += max(0ll, A[i]-tmp);
			}
			return cnt<=K;
		};

	ll ok{(ll)1e13+1};
	ll ng{-1};
	while (abs(ok-ng) > 1)
	{
		ll mid = (ng + ok) >> 1;
		if (isok(mid)) ok = mid;
		else ng = mid;
	}
	std::cout << ok << std::endl;
}
