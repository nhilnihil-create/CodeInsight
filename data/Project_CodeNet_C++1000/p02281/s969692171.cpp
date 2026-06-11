#include<bits/stdc++.h>

using namespace std;
#define NIL -1

struct node{int p,r,l;};

node tree[30];
int n;

void preorder(int u){
  if(u==NIL) return;
  cout<<" "<<u;
  preorder(tree[u].r);
  preorder(tree[u].l);
}

void inorder(int u){
  if(u==NIL) return;
  inorder(tree[u].r);
  cout<<" "<<u;
  inorder(tree[u].l);
}

void postorder(int u){
  if(u==NIL) return; 
  postorder(tree[u].r);
  postorder(tree[u].l);
  cout<<" "<<u;
}

int main(){
  int n;
  int num,r,l,A,root;
  cin>>n;
  for(int i=0;i<n;i++){
    tree[i].p=NIL;
  }
  for(int i=0;i<n;i++){
    cin>>num>>r>>l;
    if(l!=NIL) tree[l].p=num;
    if(r!=NIL) tree[r].p=num;
    tree[num].l=l;
    tree[num].r=r;
  }
  for(int i=0;i<n;i++) if(tree[i].p==NIL) root=i;
  cout<<"Preorder"<<endl;
  preorder(root);
  cout<<endl<<"Inorder"<<endl;
  inorder(root);
  cout<<endl<<"Postorder"<<endl;
  postorder(root);
  cout<<endl;
  return 0;
}
  


