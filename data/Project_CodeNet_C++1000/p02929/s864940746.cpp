#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 212345
char *s = new char[N];
int a[N];
#define MOD 1'000'000'007LL;

int main(){
	int n; scanf("%d%s", &n, s+1);
	s[0] = s[2*n+1] = 'W';
	a[0] = 1;
	FOR(i, 1, 2*n+2){
		int x = s[i-1] == s[i] ? 0 : 1;
		int y = a[i-1] == -1 ? 1 : 0;
		a[i] = x == y ? -1 : 1;
		// DEBUG("%d-%d-", x, y);
		DEBUG("%d ", a[i]);
	}
	DEBUG("\n");
	if(a[2*n+1] != -1) return printf("0\n"), 0;
	ll ans = 1;
	int x = 0;
	FOR(i, 1, 2*n+1) {
		if(a[i] == -1){
			DEBUG("%d ", x);
			ans = ans * max(x, 0) % MOD;
		}
		x += a[i];
	}
	if(x != 0) ans = 0;
	REP(i, n) ans = ans * (i+1) % MOD;
	printf("%lld\n", ans);
}
