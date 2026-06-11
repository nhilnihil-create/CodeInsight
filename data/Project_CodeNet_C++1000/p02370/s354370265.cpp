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
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;// 998244353;// ;
constexpr long long INF = numeric_limits<LL>::max() / 2;
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
struct Fll { LL first, second, third, fourd; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
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
struct Edge { LL to, cost; };
struct edge { LL from, to, cost; };
vector<vector<LL>>g;
vector<edge>edges;
vector<LL>v;
map<LL, LL>ma;
set<Pll>st;
LL h, w, n, m, k, t, s, p, q, last, cnt, sum, ans, dp[210000],a[210000], b[210000];
string str, ss;
bool f;
char c;
vector<LL> tsort(vector<vector<LL>>&g) {
	LL n = g.size();
	vector<LL>ret;
	vector<bool>used(n);
	function<void(LL)>dfs = [&](LL cur) {
		used[cur] = 1;
		rep(i, g[cur].size()) {
			if(!used[g[cur][i]])
			dfs(g[cur][i]);
		}
		ret.push_back(cur);
	};
	rep(i, n) {
		if (!used[i])dfs(i);
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int main() {
	cin >> n>>m;
	g.resize(n);
	rep(i, m) {
		LL x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	vector<LL>ts = tsort(g);
	rep(i, n) {
		cout << ts[i] << endl;
	}
	return 0;
}
