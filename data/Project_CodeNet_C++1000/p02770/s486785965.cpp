#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int K, Q;
ll d[5000];

int main() {
	cin >> K >> Q;
	REP(i, K) cin >> d[i];
	
	while (Q--) {
		ll n, x, m;
		cin >> n >> x >> m;
		
		ll ans = n - 1;
		vector<ll> cd(K);
		REP(i, K) cd[i] = d[i] % m;
		vector<ll> sum(K + 1), sumz(K + 1);
		sum[0] = sumz[0] = 0;
		REP(i, K) {
			sum[i + 1] = sum[i] + cd[i];
			sumz[i + 1] = sumz[i] + (cd[i] == 0);
		}
		ll s = x % m;
		ll c = (n - 1) / K;
		s += sum[K] * c;
		ans -= sumz[K] * c;
		
		c = (n - 1) % K;
		s += sum[c];
		ans -= sumz[c];
		
		ans -= s / m;
		cout << ans << endl;
	}
	
	return 0;
}
