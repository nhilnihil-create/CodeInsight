#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define ull unsigned long long
#define INF (1 << 30)
#define LLINF (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define eps 1e-9
#define P pair<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pul pair<ull, ull>
#define all(a) (a).begin(), (a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }

template<class T>
class Tree {
public:
	class Node {
	public:
		int parent;
		vector<int> children;
		int depth;
		T value;
	};

	vector<Node> data;
	int root = -1;
	int _size = 1;

	Tree() {
		data.resize(1);
	}
	
	void resize(int size) {
		if (size > _size) {
			while (_size < size) {
				_size *= 2;
			}
			data.resize(_size);
		}
	}
	
	void addNode(int id, vector<int>& children, T value) {
		resize(id + 1);

		if (root == -1) {
			root = id;
			data[id].parent = -1;
		}

		data[id].children = children;
		for (int i = 0; i < children.size(); ++i) {
			resize(children[i] + 1);
			if (root == children[i]) {
				root = id; 
				data[id].parent = -1;
			}
			data[children[i]].parent = id;
		}
		data[id].value = value;
	}

	void calcDepth() {
		if (root == -1) {
			return;
		}

		int depth = 0;
		queue<int> que;
		que.push(root);
		while (!que.empty()) {
			for (int i = 0, n = que.size(); i < n; ++i) {
				int parent = que.front();
				que.pop();

				data[parent].depth = depth;

				for (int j = 0; j < data[parent].children.size(); ++j) {
					que.push(data[parent].children[j]);
				}
			}
			depth++;
		}
	}
};

int main() {
	Tree<int> tree;

	int n, id, k;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> id >> k;
		v.resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> v[j];
		}
		tree.addNode(id, v, 0);
	}

	string s;
	tree.calcDepth();
	for (int i = 0; i < n; ++i) {
		if (tree.data[i].parent == -1) {
			s = "root";
		}
		else if (tree.data[i].children.size() == 0) {
			s = "leaf";
		}
		else {
			s = "internal node";
		}
		printf("node %d: parent = %d, depth = %d, %s, [", i, tree.data[i].parent, tree.data[i].depth, s.c_str());
		for (int j = 0, k = tree.data[i].children.size(); j < k; ++j) {
			printf("%d", tree.data[i].children[j]);
			if (j < k - 1)
				printf(", ");
		}
		printf("]\n");
	}

	return 0;
}