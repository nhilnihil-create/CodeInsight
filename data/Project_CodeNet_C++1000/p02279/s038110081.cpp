#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Node{
  public:
    int parent;
    int right_sibling;
    int left_child;
    int depth;
    Node(){
      parent = -1;
      right_sibling = -1;
      left_child = -1;
      depth = -1;
    }
};

void set_depth(Node* nodes,int id,int d){
  nodes[id].depth = d;
  if(nodes[id].right_sibling != -1){
    set_depth(nodes, nodes[id].right_sibling, d);
  }
  if(nodes[id].left_child != -1){
    set_depth(nodes, nodes[id].left_child, d+1);
  }
}

string type(Node* nodes, int id){
  if(nodes[id].parent == -1){
    return "root";
  }else if(nodes[id].left_child == -1){
    return "leaf";
  }else{
    return "internal node";
  }
}

string childs(Node* nodes, int id){
  int c = nodes[id].left_child;
  if(c==-1) return "";
  string childs_str = "";
  int cnt = 0;
  do{
    if(cnt) childs_str = childs_str + ", ";
    childs_str = childs_str + to_string(c);
    c = nodes[c].right_sibling;
    cnt++;
  }while(c!=-1);
  return childs_str;
}

int main(){
  int n; cin>>n;
  Node nodes[n];
  for(int i=0;i<n;i++){
    int id; cin>>id;
    int  k; 
    cin>>k;
    if(k==0) continue;
    int c[k];
    for(int j=0;j<k;j++){
      cin>>c[j];
      nodes[c[j]].parent = id;
      if(j==0){ nodes[id].left_child=c[j];
      }else{
        nodes[c[j-1]].right_sibling = c[j];
      }
    }
  }
  int root;
  for(int i=0;i<n;i++){
    if(nodes[i].parent==-1) root = i;
  }

  set_depth(nodes,root,0); 
  for(int i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, %s, [",
        i,
        nodes[i].parent,
        nodes[i].depth,
        type(nodes,i).c_str()
        );
    int c = nodes[i].left_child;
    int cnt = 0;
    while(c!=-1){
      if(cnt) printf(", ");
      printf("%d",c);
      cnt++;
      c = nodes[c].right_sibling;
    }
    printf("]\n");
  }

}