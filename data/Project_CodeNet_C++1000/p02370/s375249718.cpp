# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = std::numeric_limits<long long>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)
double h, w, n, m, k, s, t, q, last, cnt[10000], a[10000], sum, ans[10000];
string str, ss;
bool f;
char c;
int di[4][2] = { {1,0},{-1,0} ,{0,1},{0,-1} };
struct Edge { int to, cost; };
vector<Edge>vec[50000];
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

void add_edge(int a, int b, int w = 1) {
	vec[a].emplace_back(Edge{ b,w });
}

vector<int> kosaraju() {
	int sz = 0; 
    vector<Edge> rg[50000];
	vector<int> stk, cmp(n, -1), added(n), visited(n), ord(n);
	rep(i, n) {
		sz += vec[i].size();
		for (const Edge &e : vec[i])
			rg[e.to].push_back(Edge{ (int)i, e.cost });
	}
	stk.resize(n + sz); sz = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		int s = 0; stk[s++] = i;
		while (s != 0) {
			int v = stk[s - 1]; 
			visited[v] = true;
			bool pushed = false;
			for (auto &e : vec[v]) {
				int dst = e.to;
				if (!visited[dst]) { stk[s++] = dst; pushed = true; }
			}
			if (pushed) continue;
			int t = stk[s - 1];
			if (!added[t]) { added[t] = true; ord[n - ++sz] = t; }
			--s;
		}
	}
	int k = 0;
	for (int &u : ord) {
		if (cmp[u] != -1) continue;
		int s = 0; stk[s++] = u;
		while (s != 0) {
			int v = stk[--s]; cmp[v] = k;
			for (auto &e : rg[v]) {
				int d = e.to;
				if (cmp[d] == -1) stk[s++] = d;
			}
		}
		++k;
	}
	return cmp;
}
vector<int> tsort() {
	enum { YET, VISITED, DONE };
	vector<int> res, flg(n, YET);
	static const function<bool(int)> dfs = [&](int v) {
		flg[v] = VISITED;
		for (auto &e : vec[v]) {
			int w = e.to;
			if (flg[w] != DONE && (flg[w] == VISITED || !dfs(w))) return false;
		}
		flg[v] = DONE;
		res.push_back(v);
		return true;
	};
	for (int i = 0; i < n; ++i)
		if (flg[i] == YET && !dfs(i)) return{};
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	cin >> n>>m;
	rep(i, m) {
		LL x, y;
		cin >> x >> y;
		add_edge(x, y);
	}
	vector<int>cm = tsort();
	rep(i, n)
		cout << cm[i] << endl;
	return 0;
}
