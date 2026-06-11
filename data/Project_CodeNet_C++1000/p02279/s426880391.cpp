#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 1000005
#define NIL -1

struct Node { int p, l, r; };

Node T[MAX];
int n, D[MAX];

void print(int u) {
	int i, c;
	printf("node %d: ", u);
	printf("parent = %d", T[u].p);
	printf(", ");
	printf("depth = %d", D[u]);
	printf(", ");

	if (T[u].p == NIL) {
		printf("root,");
	}
	else if (T[u].l == NIL) {
		printf("leaf,");
	}
	else {
		printf("internal node,");
	}

	printf(" [");
	for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
		if (i != 0) { printf(", "); }
			printf("%d", c);
	}
	printf("]\n");
}

//再帰的に深さを求める
int rec(int u, int p) {
	D[u] = p;
	if (T[u].r != NIL) {
		rec(T[u].r, p);//右の兄弟にも同じ深さを設定する
	}
	if (T[u].l != NIL) {
		rec(T[u].l, p + 1);//左の子が存在する場合はその子に対して深さを一つ足して再帰呼び出しを行う
	}
	return D[u];
}


int main(void) {
	int i, j, d, v, c, l, r;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		T[i].p = T[i].l = T[i].r = NIL;//節点の初期化。この場合、どの点も他の節点とつながっていない
	}

	for (i = 0; i < n; i++) {
		scanf("%d%d", &v, &d);
		for (j = 0; j < d; j++) {
			scanf("%d", &c);
			if (j == 0)T[v].l = c;
			else T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	for (i = 0; i < n; i++) {
		if (T[i].p == NIL)r = i;
	}

	rec(r, 0);

	for (i = 0; i < n; i++) {
		print(i);
	}

	return 0;
}
