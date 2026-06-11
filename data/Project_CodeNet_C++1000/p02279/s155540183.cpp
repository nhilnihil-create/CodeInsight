#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAX 200000
#define NIL -1
using namespace std;
struct Node{
  int parent;
  int right;
  int left;
};

struct Node T[MAX];
//write the depth of each node
int D[MAX];

void print(int u){
  int i,c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << D[u] << ", ";        

  if(T[u].parent==NIL) cout << "root, ";   
  else if(T[u].left==NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for(i=0,c=T[u].left;c!=NIL;i++,c=T[c].right){
    if(i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}
//setting the depth of node
int rec(int u, int p){
  D[u]=p;
  if(T[u].right!=NIL) rec(T[u].right,p);
  if(T[u].left!=NIL)  rec(T[u].left,p+1);
}

int main(){
  int n,r,deg,c,id,pre=0;
  cin >> n;
  for(int i=0;i<n;i++)
    T[i].parent=T[i].right=T[i].left=NIL;

  for(int i=0;i<n;i++){
    cin >> id >> deg;
    for(int j=0;j<deg;j++){
      cin >> c;
      if(j==0) T[id].left=c;
      else T[pre].right=c;
      pre=c;
      T[c].parent=id;
    }
  }
  for(int i=0;i<n;i++)
    if(T[i].parent==NIL) r=i;
  rec(r,0);

  for(int i=0;i<n;i++) print(i);

  return 0;
}
