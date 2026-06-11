#include <iostream>
using namespace std;

const int MAX_N = 25;
int N;
int ROOT_ID;

typedef struct {
  int parent, left, right;
} node;

node nodes[MAX_N];

void preorder(int id) {
  if (id == -1) return;

  cout << ' ' << id;
  preorder(nodes[id].left);
  preorder(nodes[id].right);
}

void inorder(int id) {
  if (id == -1) return;

  inorder(nodes[id].left);
  cout << ' ' << id;
  inorder(nodes[id].right);
}

void postorder(int id) {
  if (id == -1) return;
    
  postorder(nodes[id].left);
  postorder(nodes[id].right);
  cout << ' ' << id;
}

void solve() {
  cout << "Preorder" << endl;
  preorder(ROOT_ID);
  cout << endl;

  cout << "Inorder" << endl;
  inorder(ROOT_ID);
  cout << endl;

  cout << "Postorder" << endl;
  postorder(ROOT_ID);
  cout << endl;  
}

int main() {
  for (int i = 0; i < MAX_N; i++) {
    node n;
    n.parent = n.left = n.right = -1;
    nodes[i] = n;
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    nodes[id].left = l;
    nodes[id].right = r;
    nodes[l].parent = nodes[r].parent = id;
  }

  for (int i = 0; i < N; i ++) {
    if (nodes[i].parent == -1) {
      ROOT_ID = i;
      break;
    }
  }

  solve();

  return 0;
}