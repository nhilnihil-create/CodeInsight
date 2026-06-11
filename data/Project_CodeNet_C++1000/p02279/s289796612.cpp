#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

struct Node { int p, l, r; };

int main() {
	int n;
	cin >> n;
	Node *u = new Node[n];
	for (int i = 0; i < n; i++)
		u[i].p = u[i].l = u[i].r = -1;
	for (int i = 0; i < n; i++) {
		int id, k;
		cin >> id >> k;
		if (k) {
			int *c = new int[k];
			for (int j = 0; j < k; j++)
				cin >> c[j];
			u[id].l = c[0];
			for (int j = 0; j < k; j++) {
				u[c[j]].p = id;
				if (j + 1 != k)
					u[c[j]].r = c[j+1];
			}
			delete[] c;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "node " << i;
		cout << ": parent = " << u[i].p;
		int depth = 0;
		for (int id = i; u[id].p != -1; depth++)
			id = u[id].p;
		cout << ", depth = " << depth;
		if (u[i].p == -1)
			cout << ", root";
		else if (u[i].l == -1)
			cout << ", leaf";
		else
			cout << ", internal node";
		cout << ", [";
		int ifs = 1;
		for (int id = u[i].l; id != -1; id = u[id].r) {
			if (ifs == 0)
				cout << ", ";
			cout << id;
			ifs = 0;
		}

		cout << "]";
		cout << endl;
	}
	delete[] u;

	return 0;
}