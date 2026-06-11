#include<stdio.h>
#include<algorithm>
using namespace std;
#define NIL -1
#define MAX 25

struct Node { int parent, left, right; };
struct Node T[MAX];
int D[MAX], H[MAX];

void Preorder(int p) {
  printf(" %d", p);
  if (T[p].left != NIL) Preorder(T[p].left);
  if (T[p].right != NIL) Preorder(T[p].right);
}

void Inorder(int p) {
  if (T[p].left != NIL) Inorder(T[p].left);
  printf(" %d", p);
  if (T[p].right != NIL) Inorder(T[p].right);
}

void Postorder(int p) {
  if (T[p].left != NIL) Postorder(T[p].left);
  if (T[p].right != NIL) Postorder(T[p].right);
  printf(" %d", p);
}

int main() {
	int n;
  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }

  int id, left, right;
  for ( int i = 0; i < n; i++ ) {
    scanf("%d %d %d", &id, &left, &right);
    T[id].left = left;
    T[id].right = right;
    if (left != NIL) T[left].parent = id;
    if (right != NIL) T[right].parent = id;
  }

  int p;
  for ( int i = 0; i < n; i++ ) {
    if (T[i].parent == NIL) {
      p = i;
    }
  }

  printf("Preorder\n");
  Preorder(p);
  printf("\n");
  printf("Inorder\n");
  Inorder(p);
  printf("\n");
  printf("Postorder\n");
  Postorder(p);
  printf("\n");

  return 0;
}

