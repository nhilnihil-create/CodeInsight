#include <iostream>

using namespace std;

static const int NIL = -1;
struct node {
  int p;
  int r;
  int l;
};

node tree[9999];


int depth(int u){
  int d = 0;
  while(tree[u].p != NIL){
    u = tree[u].p;
    d++;
  }
return d;
}

int printh(int u){
  int h1 ,h2;
  h1 = h2 = 0;
  if(tree[u].l != NIL) h1 = printh(tree[u].l) + 1;
  if(tree[u].r != NIL) h2 = printh(tree[u].r) + 1;
  return max(h1 , h2);
}


int printsib(int u){
  int c;
  if(tree[u].p != NIL) c = tree[u].p;
  else return NIL;
  if(tree[c].r != u && tree[c].r != NIL) return tree[c].r;
  else if(tree[c].l != u && tree[c].l != NIL) return tree[c].l;
  else return NIL;
}

int printdeg(int u){
  if(tree[u].r != NIL && tree[u].l != NIL) return 2;
  else if((tree[u].r != NIL && tree[u].l == NIL) || (tree[u].r == NIL && tree[u].l != NIL)) return 1;
  else return 0;
}

void preorder(int u){
if(u == NIL) return;

cout << ' ' << u;
preorder(tree[u].l);
preorder(tree[u].r);
}

void inorder(int u){
  if(u ==NIL) return;
  if(tree[u].l != NIL) inorder(tree[u].l);
  cout << ' ' << u;
  if(tree[u].r != NIL) inorder(tree[u].r);
}

void postorder(int u){
  if(tree[u].l != NIL) postorder(tree[u].l);
  if(tree[u].r != NIL) postorder(tree[u].r);
  cout << ' ' << u ;
}
void print(int u){

cout << "Preorder" << endl;
preorder(u);
cout << endl;

cout << "Inorder" << endl;
inorder(u);
cout << endl;

cout << "Postorder" << endl;
postorder(u);
cout << endl;
}

int main(){

  int n,u,c1,c2;
  cin >> n;
  for(int i = 0;i < n;i++) tree[i].p = tree[i].r = tree[i].l = -1;
  for(int i = 0;i < n;i++){
    cin >> u ;
    cin >> tree[u].l >> tree[u].r;
    c1 = tree[u].l;
    c2 = tree[u].r;
    if( c1 != NIL ) tree[c1].p = u;
    if( c2 != NIL ) tree[c2].p = u;
  }
  int root;
  for(int i = 0;i < n;i++) if(tree[i].p == NIL) root = i;
 print(root);

}