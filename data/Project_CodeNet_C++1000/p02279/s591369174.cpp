#include <iostream>
using namespace std;
#define NIL -1
#define MAX 100005

class Tree{
private:
  struct Node{
    int parent, left, right;
  };
public:
  Node node[MAX];
  int depth[MAX];
  void setDepth(int u, int p);
  void printNodeInf(int u);
};

void Tree::setDepth(int u, int p){
  depth[u] = p;
  if(node[u].right != NIL){
    setDepth(node[u].right, p);
  }
  if(node[u].left != NIL){
    setDepth(node[u].left, p + 1);
  }
}

void Tree::printNodeInf(int u){
  int c = node[u].left;
  cout << "node " << u << ": ";
  cout << "parent = " << node[u].parent << ", ";
  cout << "depth = " << depth[u] << ", ";

  if(node[u].parent == NIL) cout << "root, ";
  else if(node[u].left == NIL) cout << "leaf, ";
  else cout << "internal node, ";
  cout << "[";

  for(int i = 0; c != NIL; i++, c = node[c].right){
    if(i != 0) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int main(void){
  int n, id, k, c, l, r;
  Tree tree;
  cin >> n;

  for(int i = 0; i < n; i++){
    tree.node[i].parent = tree.node[i].left = tree.node[i].right = NIL;
  }

  for(int i = 0; i < n; i++){
    cin >> id >> k;
    for(int j = 0; j < k; j++){
      cin >> c;
      if(j == 0) tree.node[id].left = c;
      else tree.node[l].right = c;
      l = c;
      tree.node[c].parent = id;
    }
  }

  for(int i = 0; i < n; i++){
    if(tree.node[i].parent == NIL) r = i;
  }

  tree.setDepth(r, 0);
  for(int i = 0; i < n; i++) tree.printNodeInf(i);
  return 0;
}