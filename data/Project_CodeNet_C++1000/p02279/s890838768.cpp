#include<iostream>
using namespace std;
#define MAX 100010
#define KAZU -1

struct Node{int parent, left, right;};

Node T[MAX];
int n, D[MAX];

void print(int u){
  int i,c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << D[u] << ", ";

  if(T[u].parent == KAZU) cout << "root, ";
  else if(T[u].left == KAZU) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";

  for(i=0,c = T[u].left;c != KAZU;i++,c=T[c].right){
    if(i) cout << ", ";
    cout << c;
  }
    cout << "]" << endl;
}

int getdepth(int u,int p){
  D[u] = p;
  if(T[u].right != KAZU) getdepth(T[u].right,p);
  if(T[u].left != KAZU) getdepth(T[u].left,p+1);
}

int main(){
  int i,j,d,v,c,l,r;
  cin >> n;
  for(i=0;i<n;i++) T[i].parent = T[i].left = T[i].right = KAZU;

  for(i=0;i<n;i++){
    cin >> v >> d;
    for(j=0;j<d;j++){
      cin >> c;
      if(j==0) T[v].left = c;
      else T[l].right = c;
      l = c;
      T[c].parent = v;
    }
  }

  for(i=0;i<n;i++){
    if(T[i].parent == KAZU) r = i;
  }

  getdepth(r,0);
  for(i=0;i<n;i++) print(i);

  return 0;
}


