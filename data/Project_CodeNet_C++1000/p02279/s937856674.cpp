#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define MAX 100100
#define NIL -1
using namespace std;

typedef struct node{
  int parent, left, right;
}Node;

Node T[MAX];
int depth[MAX];

int seekroot(int id){
  while (T[id].parent != NIL){
    id = T[id].parent;
  }
  return id;
}

void setDepth(int id, int d){
  depth[id] = d;

  if (T[id].right != NIL){
    setDepth(T[id].right, d);
  }
  if (T[id].left != NIL){
    setDepth(T[id].left, d+1);
  }
  return;
}

string type(int id){
  if (T[id].parent == NIL){
    return "root";
  }else if (T[id].left == NIL){
    return "leaf";
  }else{
    return "internal node";
  }
}

string child(int id){
  string ans = "[";

  if (T[id].left != NIL){
    ans.append(to_string(T[id].left));
    id = T[id].left;
  
    while(T[id].right != NIL){
      ans.append(", ");
      ans.append(to_string(T[id].right));
      id = T[id].right;
    }

  }

  ans.append("]");

  return ans;
}

int main(){
  int n;
  cin >> n;

  rep(i, n){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
    depth[i] = NIL;
  }
  

  rep(i, n){
    int id;
    int k;
    int c[k+3]; // ループ内で何回も定義し直すとダメだった。node数が4ならできたし，node数が13個の時でも場合によって可能であった。


    cin >> id >> k;
    if(k != 0){
      rep(j, k) cin >> c[j];

      T[id].left = c[0];
      rep(j, k) T[c[j]].parent = id;
      rep(j, k-1) T[c[j]].right = c[j+1];
    }
  }

  int root = seekroot(0);
  setDepth(root, 0);


  rep(i, n){
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "depth = " << depth[i] << ", ";
    cout << type(i) << ", ";
    cout << child(i) << endl;
    // printf("node %d: parent = %d, depth = %d, %s, %s\n", i, T[i].parent, depth(i), type(i), child(i));
  }

  return 0;
}


