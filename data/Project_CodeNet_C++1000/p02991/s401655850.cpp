#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int inf = 1e9 + 10;

int N, M;
int d[3][100010];
vector<int> G[100010];
int S, T;

signed main()
{
	cin >> N >> M;

	rep(i, M) {
		int u, v; cin >> u >> v;
		--u, --v;
		G[u].PB(v);
	}

	cin >> S >> T;
	--S, --T;

	memset(d, -1, sizeof d);
	d[0][S] = 0;

	queue<pii> q;
	q.push(pii(0, S));

	while (q.size()) {
		pii p = q.front(); q.pop();
		int state = p.fst, cur = p.scd;
		int nxtstate = (state + 1) % 3;

		for (int &nxt : G[cur]) {
			if (d[nxtstate][nxt] != -1) continue;
			d[nxtstate][nxt] = d[state][cur] + 1;
			q.push(pii(nxtstate, nxt));
		}
	}

	if (d[0][T] == -1) {
		cout << -1 << endl;
	} else {
		cout << d[0][T] / 3 << endl;
	}
}

