#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1 ; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1 ; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9+100;
const bool debug = 0;
/***************************************/

int N;
int a[1000];

int main() {
	while (cin >> N, N) {
		REP(i, N) scanf("%d", a + i);
		sort(a, a + N);
		
		int ans = INF;
		REP(i, N - 1) chmin(ans, a[i + 1] - a[i]);
		if (debug) printf("@ ");
		cout << ans << endl;
	}
	return 0;
}
