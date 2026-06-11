#include <iostream>
using namespace std;

const int maxn=100000;

struct Tree {
  int parent,left,right;
};

Tree tree[maxn]; int depth[maxn];

void print(int u) {
  cout<<"node "<<u<<": "<<flush;
  cout<<"parent = "<<tree[u].parent<<", "<<flush;
  cout<<"depth = "<<depth[u]<<", "<<flush;

  if (tree[u].parent==(-1)) {
    cout<<"root, "<<flush;
  }
  else if (tree[u].left==(-1)) {
    cout<<"leaf, "<<flush;
  }
  else {
    cout<<"internal node, "<<flush;
  }
  cout<<"["<<flush;
  for (int i=0,c=tree[u].left; c!=(-1); i++,c=tree[c].right) {
    if (i) {
      cout<<", "<<flush;
    }
    cout<<c<<flush;
  }
  cout<<"]"<<endl;
}
void Depth(int u,int dpt) {
  depth[u]=dpt;
  if (tree[u].right!=(-1)) {
    Depth(tree[u].right,dpt);
  }
  if (tree[u].left!=(-1)) {
    Depth(tree[u].left,dpt+1);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n; cin>>n;
  for (int i=0; i<n; i++) {
    tree[i].parent=tree[i].left=tree[i].right=(-1);
  }
  int l;
  for (int j=0; j<n; j++) {
    int id,k; cin>>id>>k;
    for (int i=0; i<k; i++) {
      int c; cin>>c;
      if (i==0) {
	tree[id].left=c;
      }
      else {
	tree[l].right=c;
      }
      l=c;
      tree[c].parent=id;
    }
  }
  int x;
  for (int i=0; i<n; i++) {
    if (tree[i].parent==(-1)) {
      x=i;
    }
  }
  Depth(x,0);
  for (int i=0; i<n; i++) {
    print(i);
  }
  return 0;
}

