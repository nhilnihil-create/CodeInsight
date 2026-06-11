#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

int main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> graph(n + 1);
	FOR(i, 1, n-1) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(MP(b, i));
		graph[b].push_back(MP(a, i));
	}
	queue<int> que;
	que.push(1);
	vector<int> color(n);
	vector<int>fromc(n+1);
	while (!que.empty()) {
		int start = que.front();
		que.pop();
		int cnt = 1;
		for (pair<int, int> dest : graph[start]) {
			if (color[dest.S] == 0) {
				if (fromc[start] == cnt)cnt++;
				color[dest.S] = cnt;
				que.push(dest.F);
				fromc[dest.F] = cnt;
				cnt++;
			}
		}
	}
	auto itr = max_element(ALL(color));
	int res = *itr;
	pv(res);
	FOR(i, 1, n - 1) {
		pv(color[i])
	}
	return(0);
}