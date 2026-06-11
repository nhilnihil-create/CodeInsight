#ifndef VS
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<math.h>
#endif

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {
	cww() { CIN_ONLY{ ios::sync_with_stdio(false); cin.tie(0); } }
}star;
#define DEBUG if(0)
#endif

#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r) { bool a = l>r; if (a)l = r; return a; }
template <typename T>inline bool chmax(T &l, T r) { bool a = l<r; if (a)l = r; return a; }
typedef vector<LL> V;
typedef vector<V> VV;
const LL INF = 1e14;
typedef pair<LL, int> P;
int main() {
	int m;
	while (cin >> m, m) {
		VV d(10, V(10, INF));
		REP(i, 10)d[i][i] = 0;
		V e(10, 0);
		REP(i, m) {
			int a, b;LL c;
			cin >> a >> b >> c;
			chmin(d[a][b], c);
			chmin(d[b][a], c);
			e[a] = e[b] = 1;
		}
		REP(k, 10)REP(i, 10)REP(j, 10)chmin(d[i][j], d[i][k] + d[k][j]);
		P ret(INF, 0);
		REP(i, 10)if (e[i]) {
			P ans(0,i);
			REP(j, 10)if (e[j])ans.first += d[i][j];
			chmin(ret, ans);
		}
		cout << ret.second << " " << ret.first << endl;
	}
}