#include <iostream>

using namespace std;

#define MAX 100005
#define NIL -1
struct node {
  int parent;
  int left;
  int right;
};

node tree[MAX];
int d[MAX] = {};



void depth(int u,int s){
  d[u] = s;
  if(tree[u].right != NIL) depth(tree[u].right,s);
  if (tree[u].left != NIL) depth(tree[u].left, s + 1);
}

void pri(int u){
  int c;
  cout << "node " << u << ": parent = " << tree[u].parent << ", depth = " << d[u] << ", ";
  if(tree[u].parent == NIL) cout << "root, ";
  else if(tree[u].left == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";

  for(int i = 0, c = tree[u].left; c != NIL;i++, c = tree[c].right){
  if(i) cout << ", ";
  cout << c;
  }
  cout << "]" << endl;
}

int main(){

  for(int i = 0;i < MAX;i++) tree[i].parent = tree[i].left = tree[i].right = NIL;

  int n;
  cin >> n;
  int v,k,c,l,p,vp;

  for(int i = 0;i < n;i++){
    cin >> v >> k;
    for(int j = 0;j < k;j++){
      cin >> c;
      if (j == 0){
        tree[v].left = c;
        tree[c].parent = v;
        l = tree[v].left;
      }
      else {
        tree[l].right = c;
        tree[c].parent = v;
        l = c;
      }
    }
  }
  for(int i = 0;i < n;i++){
    if(tree[i].parent == NIL){
      vp = i;
      break;
    }
  }
  depth(vp,0);
for(int i = 0;i < n;i++) pri(i);

}