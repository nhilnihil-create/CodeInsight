#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define PI acos(-1)
#define Mod (int)1000000007
#define INFTY (int)INT_MAX
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Part(vec, b, e) vec.begin() + b, vec.begin() + e
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define Find(vec, s) vec.find(s) != vec.end()
#define Set_union(A, B, res) set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));
#define Set_intersection(A, B, res) set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));
#define Set_difference(A, B, res) set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));
#define Set_symmetric_difference(A, B, res) set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));

struct UnionFind {
	vector<int> par;
	int group_count;

	UnionFind(int N) {
		par = vector<int>(N, -1);
		group_count = N;
	}

	int root(int x) {
		if (par[x] < 0) return x;
		return par[x] = root(par[x]);
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	void unite(int x, int y) {
		x = root(x), y = root(y);
		if (x != y) {
			if (par[x] > par[y]) swap(x, y);
			par[x] += par[y];
			par[y] = x;
			group_count--;
		}
	}

	int size(int x) {
		return -par[root(x)];
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	UnionFind UF(N);
	int A, B;
	Rep(i, M) {
		cin >> A >> B;
		A--, B--;
		UF.unite(A, B);
	}
	cout << UF.group_count - 1 << endl;
	return 0;
}