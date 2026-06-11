#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

#define MAX 100001

struct Node {
	int p, l, r; //?????????????????¨???
};
struct Node T[MAX];
int D[MAX];

//??¨node?????±??????D???????´?
void rec(int u, int p) {
	D[u] = p;
	if (T[u].r != -1) {
		rec(T[u].r, p);
	}
	if (T[u].l != -1) {
		rec(T[u].l, p + 1);
	}
}

void print(int u) {
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].p << ", ";
	cout << "depth = " << D[u] << ", ";

	if (T[u].p == -1) { cout << "root, "; }
	else if (T[u].l == -1) { cout << "leaf, "; }
	else { cout << "internal node, "; }

	cout << "[";

	for (int i = 0, c = T[u].l; c != -1; i++, c = T[c].r) {
		if (i) { cout << ", "; }
		cout << c;
	}
	cout << "]" << endl;
}

int main() {
	int n; cin >> n;

	//?????????
	for (int i = 0; i < n; i++) {
		T[i].p = T[i].l = T[i].r = -1;
	}

	for (int i = 0; i < n; i++) {
		int id, k; cin >> id >> k;
		int l = 0;

		//?????????????????????
		for (int j = 0; j < k; j++) {
			int c; cin >> c;

			//?????????????¨????
			if (j == 0) { T[id].l = c; }
			//???(l)????????????(r)????¨????
			else { T[l].r = c; }

			//?????????????¨????
			T[c].p = id; 
			l = c;
		}
	}

	//??????????????????
	int r;
	for (int i = 0; i < n; i++) {
		if (T[i].p == -1) { r = i; }
	}

	rec(r, 0);

	for (int i = 0; i < n; i++) {
		print(i);
	}

	return 0;
}