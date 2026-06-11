#include <bits/stdc++.h>
using namespace std;

#define NIL -1

struct node {
	int p, l, r;
};

node T[100000];

int getdepth(int u) {
	int ans = 0;
	while (T[u].p != NIL) {
		ans++;
		u = T[u].p;
	}
	return ans;
}

void printchildren(int u) {
	cout << "[";
	int c = T[u].l;
	while (c != NIL) {
		if (T[c].r != NIL)
			cout << c << ", ";
		else
			cout << c;
		c = T[c].r;
	}
	cout << "]" << endl;
}

void initnode(int n) {
	for (int i = 0; i < n; i++) {
		T[i] = { NIL, NIL, NIL };
	}
}

void regnode(int id, int k, int c[]) {
	for (int j = 0; j < k; j++) {
		if (j == 0)
			T[id].l = c[0];
		if (j < k - 1)
			T[c[j]].r = c[j + 1];
		T[c[j]].p = id;
	}
}

string gettype(int id) {
	if (T[id].p == NIL)
		return "root";
	else if (T[id].l == NIL)
		return "leaf";
	else
		return "internal node";
}

int main() {
	int n;
	cin >> n;
	initnode(n);
	for (int i = 0; i < n; i++) {
		int id, k;
		cin >> id >> k;
		int c[k];
		for (int j = 0; j < k; j++) {
			cin >> c[j];
		}
		regnode(id, k, c);
	}
	for (int i = 0; i < n; i++) {
		cout << "node " << i << ": parent = " << T[i].p << ", depth = "
				<< getdepth(i) << ", " << gettype(i) << ", ";
		printchildren(i);
	}
	return 0;
}

