#include<iostream>

using namespace std;

#define MAX 100005
#define NIL -1

struct Node {
  int parent;
  int leftChild;
  int rightSibling;
};

Node T[MAX];
int D[MAX];

void print(int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << D[u] << ", ";

  if (T[u].parent == NIL) {
    cout << "root, ";
  } else if (T[u].leftChild == NIL) {
    cout << "leaf, ";
  } else {
    cout << "internal node, ";
  }

  cout << "[";

  int i, c;
  for (i = 0, c = T[u].leftChild; c != NIL; i++, c = T[c].rightSibling) {
    if (i) {
      cout << ", ";
    }
    cout << c;
  }
  cout << "]" << endl;
}

void rec(int u, int p) {
  D[u] = p;
  if (T[u].rightSibling != NIL) {
    rec(T[u].rightSibling, p);
  }
  if (T[u].leftChild != NIL) {
    rec(T[u].leftChild, p + 1);
  }
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    T[i].parent = T[i].leftChild = T[i].rightSibling = NIL;
  }

  int child, v, d, left;
  for (int i = 0; i < N; i++) {
    cin >> v >> d;
    for (int j = 0; j < d; j++) {
      cin >> child;
      if (j == 0) {
        T[v].leftChild = child;
      } else {
        T[left].rightSibling = child;
      }
      left = child;
      T[child].parent = v;
    }
  }

  int root;
  for (int i = 0; i < N; i++) {
    if(T[i].parent == NIL) {
      root = i;
    }
  }

  rec(root, 0);

  for (int i = 0; i < N; i++) {
    print(i);
  }

  return 0;
}

