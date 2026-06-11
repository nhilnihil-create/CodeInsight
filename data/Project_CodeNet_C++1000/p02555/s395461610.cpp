#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
#define double long double
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
#define eps 1e-12 
//priority_queue<int,vector<int>, greater<int> > q2;


ll comb(ll N_, ll C_) {
	const int NUM_ = 3000001;
	static ll fact[3000002], factr[3000002], inv[3000002];
	if (fact[0] == 0) {
		inv[1] = fact[0] = factr[0] = 1;
		for (int i = 2; i <= NUM_; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		for (int i = 1; i <= NUM_; ++i) fact[i] = fact[i - 1] * i%mod, factr[i] = factr[i - 1] * inv[i] % mod;
	}
	if (C_<0 || C_>N_) return 0;
	return factr[C_] * fact[N_] % mod*factr[N_ - C_] % mod;
}
ll modpow(ll a, ll n = mod - 2) {
	ll r = 1;
	while (n) r = r * ((n % 2) ? a : 1) % mod, a = a * a%mod, n >>= 1;
	return r;
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int S; cin >> S;
	int ans = 0;

	eFOR(i, 1, S) {
		int cnt = S - i * 3;
		if (cnt < 0)break;
		ans += comb(cnt + i - 1, cnt);
		ans %= mod;
		//comb(S + L - 1, S);
	}

	cout << ans << endl;

	return 0;
}

