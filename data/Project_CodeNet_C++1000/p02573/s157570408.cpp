#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P=pair<int, int>;

struct UnionFind
{
	vector<int> uni;

	UnionFind(int n) : uni(n, -1) {}
	int root(int a)
	{
		if (uni[a] < 0) return a;
		return uni[a] = root(uni[a]);
	}

	bool connect(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a == b) return false;
		if (uni[a] > uni[b])
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}
		uni[a] = uni[a] + uni[b];
		uni[b] = a;
		return true;
	}

	bool isConnect(int a, int b)
	{
		return root(a) == root(b);
	}

	int size(int a)
	{
		return -uni[root(a)];
	}
};

signed main(void)
{
	int n;
	int m;
	int mx;

	cin >> n >> m;
	UnionFind uf(n);
	rep(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (!uf.isConnect(a, b)) uf.connect(a, b);
	}
	mx = 0;
	rep(i, n)
		mx = max(mx, uf.size(i));
	cout << mx << endl;
	return 0;
}
