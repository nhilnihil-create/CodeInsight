#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")


// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
// initialize: UnionFind UF(N)

class UnionFind {                                              // OOP style
private:
	vector<int> p, rank, setSize;
	// p = path toward the root of disjoint set; p[i] = i means it is root
	// rank = upper bound of the actual height of the tree; not reliable as accurate measure
	// setSize = size of each disjoint set

	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;	// each belongs to its own set
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));		// path compression: cut short of the path if possible
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}

	int numDisjointSets() {		// # of disjoint sets
		return numSets;
	}

	int sizeOfSet(int i) {		// size of set
		return setSize[findSet(i)];
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q, i, j, k, a, b, t, ans;
	cin >> n >> q;
	
	UnionFind uf(n + 1);

	while (q--) {
		cin >> t >> a >> b;
		if (t == 0) uf.unionSet(a, b);
		else {
			if (uf.isSameSet(a, b)) cout << "1\n";
			else cout << "0\n";
		}
	}

	return 0;
}

