#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define _USE_MATH_DEFINES
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0,1,0,-1 };
const ll dy[4] = { -1, 0, 1,0 };
const ll INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
double mysqrt(double x) {
	double l = 0, r = x;
	for (int i = 0; i < 64; ++i) {
		double m = (l + r) / 2.0;
		if (m*m < x)l = m;
		else r = m;
	}
	return l;
}
///////////////////////////////////////

//DAG(有向無閉路グラフ)<=>トポロジカルソートができる
//方法１
//入次数が0の頂点があればその頂点をソート後の結果に追加しその頂点と隣接した頂点の
//入次数を-1するこれを入次数が0の頂点がなくなるまで繰り返すO(V+E)
//方法２
//すべての点から深さ優先探索を行いその帰りかけ順がトポロジカルソートの結果
vector<int>g[100010];//グラフの隣接リスト
int h[100010];//頂点の入次数を管理
int main() {
	int v, e; cin >> v >> e;
	REP(i, e) {
		int s, t;
		cin >> s >> t;
		g[s].push_back(t);
		h[t]++;
	}
	stack<int>st;
	REP(i, v)if (h[i] == 0)st.push(i);
	//ソートされた後のグラフ
	vector<int>ans;
	while (st.size()) {
		int i = st.top(); st.pop();
		ans.push_back(i);
		for (auto j : g[i]) {
			h[j]--;
			if (h[j] == 0)st.push(j);
		}
	}
	for (int i : ans)cout << i << endl;
	return 0;
}

