#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

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
	int n, q;
	cin >> n >> q;
	UnionFind uf(n);
	rep(i, q)
	{
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0)
		{
			if (!uf.isConnect(u, v)) uf.connect(u, v);
		}
		else if (t == 1)
		{
			if (uf.isConnect(u, v))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}
