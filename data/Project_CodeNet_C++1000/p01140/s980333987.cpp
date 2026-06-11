#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)

#define FOR(i,m,n) for(int i=(m);i<(n);i++)
#define int long long
#define ALL(x) (x).begin(),(x).end()
typedef pair<int, int> pii;


void solve() {
	int N, M; cin >> N >> M;
    if(N==0)exit(0);
	vector<int>H(N + 1), W(M + 1);
	REP(i, N) {
		cin >> H[i + 1];
	}
	REP(i, M) {
		cin >> W[i + 1];
	}
	REP(i, N) {
		H[i + 1] += H[i];
	}
	REP(i, M) {
		W[i + 1] += W[i];
	}
	map<int, int>mp;
	REP(i, N) {
		FOR(j, i + 1, N + 1) {
			int d = H[j] - H[i];
			mp[d]++;
		}
	}
	int ans = 0;
	REP(i, M) {
		FOR(j, i + 1, M + 1) {
			int d = W[j] - W[i];
			ans += mp[d];
		}
	}
	cout << ans << endl;
}

signed main() {
	while(true)solve();
}

