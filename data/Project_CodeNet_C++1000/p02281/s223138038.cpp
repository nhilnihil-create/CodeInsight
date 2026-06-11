#include <bits/stdc++.h>
using namespace std;

struct Node {
  int parent;
  int left, right;
  int depth;
  int sibling;
};

void preorder(vector<Node>& tree, int v) {
  cout << " " << v;  
  if ( tree[v].left >= 0 ) preorder(tree, tree[v].left);
  if ( tree[v].right >= 0 ) preorder(tree, tree[v].right);
}

void inorder(vector<Node>& tree, int v) {
  if ( tree[v].left >= 0 ) inorder(tree, tree[v].left);
  cout << " " << v;  
  if ( tree[v].right >= 0 ) inorder(tree, tree[v].right);
}

void postorder(vector<Node>& tree, int v) {
  if ( tree[v].left >= 0 ) postorder(tree, tree[v].left);
  if ( tree[v].right >= 0 ) postorder(tree, tree[v].right);
  cout << " " << v;  
}

int main() {
  int n;
  cin >> n;

  vector<Node> tree(n);
  bool used[n] = {0};
  for ( int i = 0; i < n; i++ )
    tree[i].left = tree[i].right = -1;
  
  for ( int i = 0; i < n; i++ ) {
    int id;
    cin >> id;
    int c1, c2;
    cin >> c1 >> c2;
    tree[id].left = c1;
    if ( c1 >= 0 ) {
      used[c1] = true;
      tree[c1].sibling = c2;
    }
    tree[id].right = c2;
    if ( c2 >= 0 ) {
      used[c2] = true;
      tree[c2].sibling = c1;
    }
  }

  int root;
  for ( int i = 0; i < n; i++ ) {
    if ( !used[i] ) {
      root = i;
      break;
    }
  }

  //cout << tree[root].left << " " << tree[root].right << endl;
  
  cout << "Preorder" << endl;
  preorder(tree, root);
  cout << endl;

  cout << "Inorder" << endl;
  inorder(tree, root);
  cout << endl;

  cout << "Postorder" << endl;
  postorder(tree, root);
  cout << endl;
  
  return 0;
}

