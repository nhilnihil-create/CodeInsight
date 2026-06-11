#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node *p, *l, *r;
};

Node *null, *root;

void Print_P(Node *T) {
  if (T == null)
    return;
  printf(" %d", T->key);
  Print_P(T->l);
  Print_P(T->r);
}

void Print_M(Node *T) {
  if (T == null)
    return;
  Print_M(T->l);
  printf(" %d", T->key);
  Print_M(T->r);
}

void Insert(int k) {
  Node *y = null, *x = root, *z = (Node *)malloc(sizeof(Node));
  z->key = k, z->l = null, z->r = null;
  while (x != null) {
    y = x;
    if (z->key < x->key)
      x = x->l;
    else
      x = x->r;
  }
  z->p = y;

  if (y == null)
    root = z;
  else if (z->key < y->key)
    y->l = z;
  else
    y->r = z;
}

int main() {
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    char o[7];
    scanf("%s", o);
    if (strcmp(o, "insert") == 0) {
      int k;
      scanf("%d", &k);
      Insert(k);
    } else {
      Print_M(root);
      printf("\n");
      Print_P(root);
      printf("\n");
    }
  }
}
