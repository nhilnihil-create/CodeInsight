#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define NIL -1
#define N 100005

//struct Node{
//	int val;
//	Node *p, *l, *r;
//};

struct Node {
	int p, l, r;
	Node():p(NIL), l(NIL), r(NIL){}
};

Node T[N];
int D[N];

void print(int u){
	printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);

	if (T[u].p == NIL) printf("root, ");
	else if (T[u].l == NIL) printf("leaf, ");
	else printf("internal node, ");

	printf("[");
	for (int i = 0, c = T[u].l; c != NIL; c = T[c].r) {
		if (i++) printf(", ");
		printf("%d", c);
	}
	printf("]\n");
}

void rec(int u, int d){
	D[u] = d;
	if (T[u].l != NIL) rec(T[u].l, d + 1);
	if (T[u].r != NIL) rec(T[u].r, d);
}


int main(){
	int n; scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int u, d; scanf("%d %d", &u, &d);

		int l;
		for (int j = 0; j < d; ++j){
			int v; cin >> v;
			if (j == 0){
				T[u].l = v;
			}
			else T[l].r = v;
			l = v;
			T[v].p = u;
		}
	}

	int root;
	for (int i = 0; i < n; ++i) {
		if (T[i].p == NIL) root = i;
	}
	rec(root, 0);
	for (int i = 0; i < n; ++i) print(i);

	return 0;
}

//node 0: parent = -1, depth = 0, root, [1, 4, 10]
//node 1 : parent = 0, depth = 1, internal node, [2, 3]
//node 2 : parent = 1, depth = 2, leaf, []
//node 3 : parent = 1, depth = 2, leaf, []
//node 4 : parent = 0, depth = 1, internal node, [5, 6, 7]
//node 5 : parent = 4, depth = 2, leaf, []
//node 6 : parent = 4, depth = 2, leaf, []
//node 7 : parent = 4, depth = 2, internal node, [8, 9]
//node 8 : parent = 7, depth = 3, leaf, []
//node 9 : parent = 7, depth = 3, leaf, []
//node 10 : parent = 0, depth = 1, internal node, [11, 12]
//node 11 : parent = 10, depth = 2, leaf, []
//node 12 : parent = 10, depth = 2, leaf, []