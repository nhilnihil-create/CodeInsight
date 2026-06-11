#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
int main() {
	while (1) {
		int H, W; cin >> H >> W;
		if (!H)break;
		UnionFind uf(H*W);
		vector<string>field(H);
		for (int i = 0; i < H; ++i) {
			cin >> field[i];
		}
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (j!=W-1&&field[i][j] == field[i][j + 1]) {
					uf.unionSet(i*W + j, i*W + j + 1);
				}
				if (i!=H-1&&field[i][j] == field[i + 1][j]) {
					uf.unionSet(i*W + j, (i + 1)*W + j);
				}
			}
		}
		set<int>aset;
		for (int i = 0; i < H*W; ++i) {
			aset.emplace(uf.root(i));
		}
		cout << aset.size() << endl;
	}
	return 0;
}