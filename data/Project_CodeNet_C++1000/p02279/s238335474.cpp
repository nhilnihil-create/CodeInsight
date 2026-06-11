#include <iostream>

using namespace std;

struct Node{ int p, l, r; };
Node tree[100000];
int depth[100000];

int n;

void print(){
  for(int i = 0; i < n; i++){
    cout << "node " << i << ": ";
    cout << "parent = " << tree[i].p << ", ";
    cout << "depth = " << depth[i] << ", ";
    if(tree[i].p == -1)
      cout << "root, ";
    else if(tree[i].l == -1)
      cout << "leaf, ";
    else
      cout << "internal node, ";
    cout << "[";
    for(int c = tree[i].l; c != -1; c = tree[c].r){
      if(c == tree[i].l)
	cout << c;
      else
	cout << ", " << c;
    }
    cout << "]" << endl;
  }
}

int depthSet(int x, int d){
  depth[x] = d;
  if(tree[x].r != -1)
    depthSet(tree[x].r, d);
  if(tree[x].l != -1)
    depthSet(tree[x].l, d+1);
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    tree[i].p = tree[i].l = tree[i].r = -1;
  }
  int lastnodeid;
  for(int i = 0; i < n; i++){
    int pid, num;
    cin >> pid >> num;
    for(int j = 0; j < num; j++){
      int id;
      cin >> id;
      if(j == 0)
	tree[pid].l = id;
      else
	tree[lastnodeid].r = id;
      tree[id].p = pid;
      lastnodeid = id;
    }
  }
  int root;
  for(int i = 0; i < n; i++){
    if(tree[i].p == -1){
      root = i;
    }
  }
  depthSet(root,0);
  print();

}