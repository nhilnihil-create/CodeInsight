#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAX 25
#define NIL -1
using namespace std;

typedef struct{
	int parent, left, right;
} Node;

Node T[MAX];

int findRoot(void){
	int u = 0;
	while(T[u].parent != NIL)
		u = T[u].parent;
	return u;
}

void preParse(int u){
	if(u == NIL)
		return;
	printf(" %d", u);
	preParse(T[u].left);
	preParse(T[u].right);
}

void inParse(int u){
	if(u == NIL)
		return;
	inParse(T[u].left);
	printf(" %d", u);
	inParse(T[u].right);
}

void postParse(int u){
	if(u == NIL)
		return;
	postParse(T[u].left);
	postParse(T[u].right);
	printf(" %d", u);
}

int main(void){
	int n, i, id, left, right, root;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		T[i].parent = NIL;
	for(i = 0;i < n;i++){
		scanf("%d %d %d", &id, &left, &right);
		T[id].left = left;
		T[id].right = right;
		if(left != NIL)
			T[left].parent = id;
		if(right != NIL)
			T[right].parent = id;
	}
	root = findRoot();
	printf("Preorder\n");
	preParse(root);
	printf("\nInorder\n");
	inParse(root);
	printf("\nPostorder\n");
	postParse(root);
	printf("\n");
	return 0;
}