#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>
#include<functional>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265358979
#define NIL -1
#define MAX 100001

using namespace std;
typedef pair<int, int> P;

struct NODE {
	int parent;
	int left;
	int right;
};

NODE tree[MAX];
int D[MAX];

void print(int u) {
	int i, c;

	cout << "node " << u << ": ";
	cout << "parent = " << tree[u].parent << ", ";
	cout << "depth = " << D[u] << ", ";

	if (tree[u].parent == NIL) {
		cout << "root, ";
	}
	else if (tree[u].left == NIL) {
		cout << "leaf, ";
	}
	else {
		cout << "internal node, ";
	}

	cout << "[";
	for (i = 1, c = tree[u].left; c != NIL; i++, c = tree[c].right) {
		if (i != 1) {
			cout << ", ";
		}
		cout << c;
	}
	cout << "]" << endl;
}

void rec(int u, int p) {
	D[u] = p;
	if (tree[u].left != NIL) {
		rec(tree[u].left, p + 1);
	}
	if (tree[u].right != NIL) {
		rec(tree[u].right, p);
	}
}

int main(void) {
	int n;
	int id, k, c, l, r;

	cin >> n;
	FOR(i, 0, n-1) {
		tree[i].parent = tree[i].left = tree[i].right = NIL;
	}

	FOR(i, 0, n-1) {
		cin >> id >> k;
		FOR(t, 0, k-1) {
			cin >> c;
			if (t == 0) {
				tree[id].left = c;
			}
			else {
				tree[l].right = c;
			}
			l = c;
			tree[c].parent = id;
		}
	}

	FOR(i, 0, n-1) {
		if (tree[i].parent == NIL) {
			r = i;
			break;
		}
	}

	rec(r, 0);

	FOR(i, 0, n-1) {
		print(i);
	}

	return 0;
}
