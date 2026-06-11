#include<bits/stdc++.h>
using namespace std;
typedef struct{
  int parent,left,right;
}node;

node tree[30];
int n;

void preset(int i){
  for(int j=0;j<i;j++)
    tree[j].parent=tree[j].left=tree[j].right=-1;
  return;
}

void preorder(int now){
  
  cout << " " << now;
  if(tree[now].left!=-1)
    preorder(tree[now].left);
  if(tree[now].right!=-1)
    preorder(tree[now].right);
 
  return;
}

void inorder(int now){

  if(tree[now].left!=-1)
    inorder(tree[now].left);
  cout << " " << now;
  if(tree[now].right!=-1)
    inorder(tree[now].right);

  return;
}

void postorder(int now){
  
  if(tree[now].left!=-1)
    postorder(tree[now].left);
  if(tree[now].right!=-1)
    postorder(tree[now].right);
  cout << " " << now;

  return;
}

main()
{

  int id,left,right;
  int root;

  cin >> n;
  preset(n);
  for(int i=0;i<n;i++){
    cin >> id >> left >> right;
    tree[id].left=left;
    tree[id].right=right;
    
    if(left!=-1)
      tree[left].parent=id;
    if(right!=-1)
      tree[right].parent=id;
    
  }

  for(int i=0;i<n;i++){
    if(tree[i].parent==-1)
      root=i;
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

  return (0);
}