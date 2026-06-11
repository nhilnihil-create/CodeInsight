#include<stdio.h>
#include<algorithm>
using namespace std;
#define NIL -1
#define MAX 100005

struct Node { int parent, left, right; };
struct Node T[MAX];
int D[MAX];

void setDepth(int u, int d) {
  D[u] = d;
  if (T[u].left != NIL) setDepth(T[u].left, d+1);
  if (T[u].right != NIL) setDepth(T[u].right, d);
}

void printChildren(int u) {
  int c = T[u].left;
  printf("[");
  if (c != NIL) {
    printf("%d", c);
    c = T[c].right;
  }
  while (c != NIL) {
    printf(", %d", c);
    c = T[c].right;
  }
  printf("]\n");
}

int main() {
	int n;
  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }
  int id, k;
  for ( int i = 0; i < n; i++ ) {
    scanf("%d %d", &id, &k);
    int c, oldc;
    for (int i = 0; i < k; i++) {
      scanf("%d", &c);
      if (i == 0) {
        T[id].left = c;
        T[c].parent = id;
        oldc = c;
      } else {
        T[oldc].right = c;
        T[oldc].parent = id;
        oldc = c;
        if (i == k-1) {
          T[oldc].parent = id;
        }
      }
    }
  }

  for ( int i = 0; i < n; i++ ) {
    if (T[i].parent == NIL) {
      setDepth(i, 0);
      break;
    }
  }

  for ( int i = 0; i < n; i++ ) {
    printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, D[i]);
    if (T[i].parent == NIL) {
      printf("root, ");
    } else if (T[i].left == NIL) {
      printf("leaf, ");
    } else {
      printf("internal node, ");
    }
    printChildren(i);
  }

  return 0;
}

