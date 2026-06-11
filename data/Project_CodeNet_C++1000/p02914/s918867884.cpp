#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const bool debug = 0;
//---------------------------------//

int N;
ll A[112345];

int main() {
	cin >> N;
	REP(i, N) scanf("%lld", A + i);
	
	ll xx = 0;
	REP(i, N) xx ^= A[i];
	
	REP(i, 61) if (xx >> i & 1) REP(j, N) if (A[j] >> i & 1) A[j] ^= 1ll << i;
	
	ll ans = xx, cur = 0;
	for (int i = 60; i >= 0; i--) {
		sort(A, A + N, greater<ll>());
		
		if ((cur >> i & 1 ^ 1) && (A[0] >> i & 1)) cur ^= A[0];
		FOR(j, 1, N) if (A[j] >> i & 1) A[j] ^= A[0];
		if (A[0] >> i & 1) A[0] = 0;
	}
	
	ans += cur * 2;
	cout << ans << endl;
	
	return 0;
}