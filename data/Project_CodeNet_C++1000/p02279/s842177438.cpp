#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
using namespace std;
const int num = 100000;
int n;
const int NIL = -1;
struct Node {
	int p, r, l;
};
Node T[num];
int D[num];
inline void rec(int u, int p) {
	D[u] = p;
	if (T[u].l != NIL)rec(T[u].l, p+1);
	if (T[u].r != NIL) rec(T[u].r, p);
}

void print(int u){
	int i;
		printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);
		if (T[u].p == NIL)printf("root, [");
		else if (T[u].l == NIL) printf("leaf, [");
		else printf("internal node, [");
		int c;
		for (i = 0, c = T[u].l; c != NIL; c = T[c].r, i++) {
		
			if (i) printf(", ");
			printf("%d", c);
		}
		
		printf("]\n");
}
int main(){
	int  numn, numc, v, parentnum, c, i, j, a;
	cin >> n;
	for (i = 0; i < n; i++)
		T[i].p = T[i].l = T[i].r = NIL;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &numn, &numc);
		for (j = 0; j < numc; j++) {
			scanf("%d", &c);
			if (j == 0)T[numn].l = c;
			else  T[v].r = c;
			v = c;
			T[c].p = numn;
		}
	}
	for (i = 0; i < n; i++)
		if (T[i].p == NIL) parentnum = i;
	rec(parentnum, 0);
	//for (i = 0; i < n; i++) print(i);
	for (a = 0; a < n; a++) {
		printf("node %d: parent = %d, depth = %d, ", a, T[a].p, D[a]);
		if (T[a].p == NIL)printf("root, [");
		else if (T[a].l == NIL) printf("leaf, [");
		else printf("internal node, [");
		for (i = 0, c = T[a].l; c != NIL; c = T[c].r, i++) {
			if (i) printf(", ");
			printf("%d", c);
		}
		printf("]\n");
	}
	return 0;

}