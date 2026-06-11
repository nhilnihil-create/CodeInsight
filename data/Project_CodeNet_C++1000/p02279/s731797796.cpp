#include<cstdio>
#define NIL -1
#define MAX 100000

typedef struct{int parent, left, right;} Node;

Node T[MAX];
int D[MAX];

int findRoot(void){
	int u = 0;
	while(T[u].parent != NIL)
		u = T[u].parent;
	return u;
}

void setDepth(int u, int p){
	D[u] = p;
	if(T[u].right != NIL)
		setDepth(T[u].right, p);
	if(T[u].left != NIL)
		setDepth(T[u].left, p+1);
}

void printChildren(int u){
	int i = 0, c = T[u].left;
	while(c != NIL){
		if(i)
			printf(", ");
		i++;
		printf("%d", c);
		c = T[c].right;
	}
}

int main(void){
	int n, i, id, k, j, a, b;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		T[i].parent = T[i].left = T[i].right = NIL;
	for(i=0;i<n;i++){
		scanf("%d %d", &id, &k);
		if(k){
			scanf("%d", &a);
			T[id].left = a;
			T[a].parent = id;
			for(j=1;j<k;j++){
				b = a;
				scanf("%d", &a);
				T[a].parent = id;
				T[b].right = a;
			}
		}
	}
	setDepth(findRoot(), 0);
	for(i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, D[i]);
		if(T[i].parent == NIL)
			printf("root, ");
		else if(T[i].left == NIL)
			printf("leaf, ");
		else
			printf("internal node, ");
		printf("[");
		printChildren(i);
		printf("]\n");
	}
	return 0;
}