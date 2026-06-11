//#define LOCAL

#include <cstdio>

#define M 100010
#define NIL -1
struct Node { int p, l, r; };
Node T[M]; int A[M];

void print(int u) {
	int i, c;
	printf("node %d: parent = %d, depth = %d, ", u, T[u].p, A[u]);
	if(T[u].p == NIL) printf("root, ");
	else if(T[u].l == NIL) printf("leaf, ");
	else printf("internal node, ");
	printf("[");
	for(i=0, c=T[u].l; c!=NIL; ++i, c=T[c].r) {
		if(i) printf(", ");
		printf("%d", c);
	}
	printf("]\n");
}

int rec(int u, int p) {
	A[u] = p;
	if(T[u].r != NIL) rec(T[u].r, p);
	if(T[u].l != NIL) rec(T[u].l, p+1);
}

int main()
{
	#ifdef LOCAL
		freopen("E:\\Temp\\input.txt", "r", stdin);
		freopen("E:\\Temp\\output.txt", "w", stdout);
	#endif

	int a, b, c, d, i, j, n, r;
	scanf("%d", &n);
	for(i=0; i<n; ++i) T[i].p = T[i].l = T[i].r = NIL;

	for(i=0; i<n; ++i) {
		scanf("%d%d", &a, &b);
		for(j=0; j<b; ++j) {
			scanf("%d", &c);
			if(!j) T[a].l = c;
			else T[d].r = c;
			d = c;
			T[c].p = a;
		}
	}
	for(i=0; i<n; ++i)
		if(T[i].p == NIL) r = i;
	rec(r, 0);

	for(i=0; i<n; ++i) print(i);

	return 0;
}