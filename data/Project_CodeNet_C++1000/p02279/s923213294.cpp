#include<stdio.h>
#include<iostream>

using namespace std;

const static int MAX = 100000;
const static int NIL = -1;

typedef struct {
  int parent;
  int left;
  int right;
} Node;

Node T[MAX];
int D[MAX];

void printChildren(int u) {
  int c = T[u].left;
  int i = 0;
  printf("[");
  while (c != NIL) {
    if (i > 0) printf(", ");
    i++;
    printf("%d", c);
    c = T[c].right;
  }
  printf("]");
}

void setDepth(int u, int p) {
  D[u] = p;
  if (T[u].left != NIL) {
    setDepth(T[u].left, p + 1);
  } 
  if (T[u].right != NIL) {
    setDepth(T[u].right, p);
  }
}

int main() {
  int n, id, m, node1, node2, root;

  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &m);

    node1 = NIL;
    for (int j = 0; j < m; j++) {
      scanf("%d", &node2);
      if (T[id].left == NIL) {
        T[id].left = node2;
      }
      T[node2].parent = id;
      if (node1 != NIL)
        T[node1].right = node2;
      node1 = node2;
    }
  }
  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) {
      root = i;
      break;
    }
  }

  setDepth(root, 0);

  for (int i = 0; i < n; i++) {
    printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, D[i]);
    if (T[i].parent == NIL) printf("root, ");
    else if (T[i].left == NIL) printf("leaf, ");
    else printf("internal node, ");
    printChildren(i);
    printf("\n");
  }

  return 0;
}

