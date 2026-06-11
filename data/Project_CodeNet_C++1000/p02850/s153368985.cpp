#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int n, k = 0;
vvi e;
map<P, int> color;

void dfs(int v, int pre = -1) {

	int no = color[P(v, pre)];
	int ec = 1;

	for (auto vv : e[v]) {
		if (vv == pre)continue;
		if (ec == no)ec++;
		color[P(v, vv)] = color[P(vv, v)] = ec;
		k = max(k, ec);
		dfs(vv, v);
		ec++;
	}
}

int main() {

	cin >> n;
	e.resize(n);
	V<P> ee(n - 1);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
		ee[i] = P(a, b);
	}

	dfs(0);

	cout << k << endl;
	for (auto p : ee)cout << color[p] << endl;
}