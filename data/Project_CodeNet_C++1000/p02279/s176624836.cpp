#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
	int parent, left, right;
};

int NIL = -1;

void calcDepth(int D[], Node T[], int i, int depth) {

	D[i] = depth;

	if (T[i].right != NIL) {
		calcDepth(D, T, T[i].right, depth);
	}
	if (T[i].left != NIL) {
		calcDepth(D, T, T[i].left, depth + 1);
	}
}

int main() {

	int MAX = 100000;

	Node T[MAX];
	int D[MAX];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		T[i].parent = T[i].left = T[i].right = NIL;
	}

	int id, k, c, preC;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &id);
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &c);
			if (j == 0) {
				T[id].left = c;
			} else {
				T[preC].right = c;
			}
			T[c].parent = id;
			preC = c;
		}
	}

	int root;
	for (int i = 0; i < n; ++i) {
		if (T[i].parent == NIL) {
			root = i;
			break;
		}
	}

	calcDepth(D, T, root, 0);

	for (int i = 0; i < n; ++i) {
		cout << "node " << i << ": parent = " << T[i].parent << ", depth = " << D[i] << ", ";
		if (i == root) {
			cout << "root";
		} else if (T[i].left == NIL) {
			cout << "leaf";
		} else {
			cout << "internal node";
		}
		cout << ", [";

		int j = 0;
		for (int c = T[i].left; c != NIL; c = T[c].right) {
			if (j) {
				cout << ", ";
			}
			cout << c;
			++j;
		}

		cout << "]" << endl;

	}

	return 0;
}