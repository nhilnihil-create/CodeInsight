#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

struct Node {
	int parent;
	vector<int> children;
	int num;
};
vector<Node> tree;

vector<int> divisor(int n)
{
	vector<int> ret;
	for (int i = 0; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n)	ret.push_back(n / i);
		}
	}
	return ret;
}
void prime_factorize(int n, map<int, int> &prime)
{
	if (n <= 1)	return;
	int last = sqrt(n);
	for (int i = 2; i <= last; i++) {
		if (n % i == 0) {
			prime_factorize(i, prime);
			prime_factorize(n / i, prime);
			return;
		}
	}
	prime[n]++;
	return;
}
void addNumberToChildren(int p, int num) {
	if (tree[p].children.size() == 0)	return;
	for (int a : tree[p].children) {
		tree[a].num += num;
		addNumberToChildren(a, num);
	}
	return;
}

vector<vector<int>> to;
vector<int> ans;
void dfs(int v, int p = -1) {
	for (int u : to[v]) {
		if (u == p)	continue;
		ans[u] += ans[v];
		dfs(u, v);
	}
}

int main()
{
	int n, q;
	cin >> n >> q;
    to.resize(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	ans.resize(n);
	rep(i, q) {
		int p, x;
		cin >> p >> x;
		p--;
		ans[p] += x;
	}
	dfs(0);
	rep(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}
