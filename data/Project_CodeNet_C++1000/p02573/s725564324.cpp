#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind
{
	vector<int> r;						//represents parent/size*(-1) at child/root

	UnionFind(int n)
	{
		r = vector<int>(n, -1);
	}

	int root(int n)
	{
		if(r[n] < 0)	return n;
		else	return r[n] = root(r[n]);
	}

	void unite(int n, int m)
	{
		n = root(n), m = root(m);
		if(n != m)
		{
			if(r[m] < r[n])	swap(m, n);	//represent larger by n
			r[n] += r[m];
			r[m] = n;
		}
	}

	int size(int n)
	{
		return -r[root(n)];
	}
};

int main()
{
	int n, m;
	cin >> n >> m;

	UnionFind UF(n);
	int a, b;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--, b--;
		UF.unite(a, b);
	}

	int ans = 0;
	for(int i = 0; i < n; i++)		//Max size set
	{
		ans = max(ans, UF.size(i));
	}

	cout << ans << endl;
}