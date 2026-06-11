#include  <iostream>
using namespace std;
static const int MAX = 100006;
static const int NO = -1;

struct node{
  int p,l,r;
};

node tree[MAX];
int d[MAX] = {};

void printchild(int u){
  int c;
  if(tree[u].l == NO) {
    cout << ']';
  }
  c = tree[u].l;
  while(c != NO){
    cout << c;
    c = tree[c].r;
    if(c != NO) cout << ", ";
    else cout << ']';
  }
}

int depth(int u){

  int e,d = 0 ;
  e = tree[u].p;
  while(e != NO){
    e = tree[e].p;
    d++;
  }
  return d;
}

void print(int u){

  d[u] = depth(u);
  cout << "node " << u <<':' ;
  cout << " parent " << "= " << tree[u].p << ',';
  cout << " depth " << "= " << d[u] << ',' ;
  if (tree[u].p == NO) {cout << " root, " << '[' ;
  printchild(u);
  cout << endl;
}
else if(tree[u].l == NO){
  cout << " leaf, " << "[]" << endl;
}
else {
  cout << " internal node, " << '[' ;
  printchild(u);
  cout << endl;
}

}



int main(){

  int n,k,u,c,e;
  cin >> n;
  for(int i = 0;i < n;i++){
    tree[i].p = NO;
    tree[i].r = NO;
    tree[i].l = NO;
  }
  for(int i = 0;i < n;i++){
    cin >> u;
    cin >> k;
    for(int j = 1;j <= k;j++){
      if(j == 1){
        cin >> e;
        tree[u].l = e;
        tree[e].p = u;
      }
      else {
        c = e;
        cin >> e;
        tree[c].r = e;
        tree[e].p = u;
      }
    }
  }
  for(int i = 0;i < n;i++) print(i);

}