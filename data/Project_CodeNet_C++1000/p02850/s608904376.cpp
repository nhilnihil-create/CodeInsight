#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}


signed main(void) {
	int n;
	cin >> n;
	vector<vector<int>>G(n);
	vector<pair<int, int>> vp;
	rep(i, n - 1) {
		int tmpa, tmpb;
		cin >> tmpa >> tmpb;
		tmpa--;
		tmpb--;
		G[tmpa].pb(tmpb);
		G[tmpb].pb(tmpa);
		vp.pb(make_pair(tmpa,tmpb));
	}
	vector<int> visited(n, -1); // 全頂点を「未訪問」に初期化
	queue<int> que;
	vector<int> cs(n, 0); // color of edge between its parent
	map<pair<int, int>, int> I;
	visited[0] = 0;
	que.push(0);
	int k = 1;

	while (!que.empty()) {
		int v = que.front();
		que.pop();
		if (k < (int)G[v].size()) k = G[v].size();
		int cur = 1;
		for (int nv : G[v]) {
			if (visited[nv] != -1) continue; // すでに発見済みの頂点は探索しない
			if (cur == cs[v])cur++;
			I[make_pair(v, nv)] = cur;
			I[make_pair(nv, v)] = cur;
			cs[nv] = cur;
			visited[nv] = 0;
			que.push(nv);
			cur++;
		}
	}
	println(k);
	for (auto v : vp)println(I[v]);
}