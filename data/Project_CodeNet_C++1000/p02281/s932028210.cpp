#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_N 25
#define NIL -1
bool is_nil(int i) {
  return i == NIL;
}

struct Node {
  int parent;
  int left;
  int right;
};
Node N[MAX_N];

void preorder(int p) {
  printf(" %d", p);
  if(!is_nil(N[p].left))
    preorder(N[p].left);
  if(!is_nil(N[p].right))
    preorder(N[p].right);
}

void inorder(int p) {
  if(!is_nil(N[p].left))
    inorder(N[p].left);
  printf(" %d", p);
  if(!is_nil(N[p].right))
    inorder(N[p].right);
}

void postorder(int p) {
  if(!is_nil(N[p].left))
    postorder(N[p].left);
  if(!is_nil(N[p].right))
    postorder(N[p].right);
  printf(" %d", p);
}

int main() {
  for(int i=0; i<MAX_N; i++) {
    N[i].parent = -1;
    N[i].left = -1;
    N[i].right = -1;
  }

  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    int id, left, right;
    cin >> id >> left >> right;

    N[id].left = left;
    N[id].right = right;
    if(!is_nil(left)) {
      N[left].parent = id;
    }
    if(!is_nil(right)) {
      N[right].parent = id;
    }
  }

  int root;
  for(int i=0; i<n; i++) {
    if(is_nil(N[i].parent)) {
      root = i;
    }
  }

  cout << "Preorder" << endl;
  preorder(root);
  cout << endl;

  cout << "Inorder" << endl;
  inorder(root);
  cout << endl;

  cout << "Postorder" << endl;
  postorder(root);
  cout << endl;

  return 0;
}