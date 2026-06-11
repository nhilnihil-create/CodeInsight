#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define NIL -1
#define MAX 100005

struct Node {
    int parent;	    //???
    int left;	    //????????\?????????
    int right;	    //?????´
};

struct Node T[MAX];
int Depth[MAX];
int n;

void rec(int u, int depth) {
    Depth[u] = depth;
    if (T[u].right != NIL) {
	rec(T[u].right, depth);
    }
    if (T[u].left != NIL) {
	rec(T[u].left, depth + 1);
    }
}

void print(int u) {
    int i, c;

    printf("node %d: ", u);
    printf("parent = %d, ", T[u].parent);
    printf("depth = %d, ", Depth[u]);

    if (T[u].parent == NIL) {
	printf("root, ");
    }
    else if (T[u].left == NIL) {
	printf("leaf, ");
    }
    else {
	printf("internal node, ");
    }
    
    printf("[");
    for (i = 0, c = T[u].left; c != NIL; i++,c=T[c].right) {
	if (i) {
	    printf(", ");
	}
	printf("%d", c);
    }
    printf("]\n");
}

int main() {
    cin.tie(0); 
    ios::sync_with_stdio(false);

    int id;
    int degree;
    int chilId;
    int left;
    int r;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	T[i].left = T[i].right = T[i].parent = NIL;
    }

    for (int i = 0; i < n; i++) {
	scanf("%d", &id);
	scanf("%d", &degree);
	for (int j = 0; j < degree; j++) {
	    scanf("%d", &chilId);
	    if (j == 0) {
		T[id].left = chilId;
	    }
	    else {
		T[left].right = chilId;
	    }
	    left = chilId;
	    T[chilId].parent = id;
	}
    }
    for (int i = 0; i < n; i++) {
	if (T[i].parent == NIL) {
	    r = i;
	}
    }

    rec(r, 0);
    
    for (int i = 0; i < n; i++) {
	print(i);
    }

    return 0;
}