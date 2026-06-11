#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

vector<vector<int>> abl;
vector<int> ans;

void Dfs(int par, int now) {
	for(auto v : abl[now]) {
		if (par == v) continue;
		ans[v] += ans[now];
		Dfs(now ,v);
	}
}

int main()
{
	int n, q;
	cin >> n >> q;
	abl.resize(n + 1);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		abl[a].push_back(b);
		abl[b].push_back(a);
	}
	ans.resize(n + 1);
	rep(i, q) {
		int p, x;
		cin >> p >> x;
		ans[p] += x;
	}
	Dfs(-1, 1);
	rep(i, n + 1) {
		if (i != 0) {
			cout << ans[i] << endl;
		}
	}
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}