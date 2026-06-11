#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAX 100009
#define NIL -1

struct Node { int p, l, r; };
Node T[MAX];
int n, D[MAX];

void setDepth(int u, int p) {
	D[u] = p;
	if (T[u].r != NIL) setDepth(T[u].r, p);
	if (T[u].l != NIL) setDepth(T[u].l, p + 1);
}

void listChild(int u) {
	int c = T[u].l;
	cout << "[";
	while (c != NIL) {
		cout << c;
		c = T[c].r;
		if(c!=NIL) cout << ", ";
	}
	cout << "]";
}

void whatType(int u) {
	if (D[u] == 0) cout << "root";
	else {
		if (T[u].l == NIL) cout << "leaf";
		else cout << "internal node";
	}
}

void print(int u) {
	cout << "node " << u << ": parent = " << T[u].p << ", depth = " << D[u] << ", ";
	whatType(u);
	cout << ", ";
	listChild(u);
	cout << "\n";
}

int main() {
	int d, v, c, l, r;
	cin >> n;
	for (int i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;

	for (int i = 0; i < n; i++) {
		cin >> v >> d;
		for (int j = 0; j < d; j++) {
			cin >> c;
			if (j == 0)  T[v].l = c;
			else  T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}

	for (int i = 0; i < n; i++) if (T[i].p == NIL) r = i;
	setDepth(r, 0);
	for (int i = 0; i < n; i++) print(i);
}