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

#define N 312345
int cnt[N] = {};
map<int, int, greater<int>> cnts, cur;
int ans[N] = {};

int main(){
	int n; scanf("%d", &n);
	REP(i, n) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	int m = 0; // number of blocks
	REP(i, N) if(cnt[i]) m++, cnts[cnt[i]]++;

	int sm = 0;
	FOR(i, 1, n+1){
		sm += i * cnts[i];
		m -= cnts[i];
		int q = m + sm/i;
		ans[q] = i;
	}

	for(int i = N-2; i>=0; i--) if(!ans[i]) ans[i]=ans[i+1];
	FOR(i, 1, n+1){
		printf("%d\n", ans[i]);
	}
}
