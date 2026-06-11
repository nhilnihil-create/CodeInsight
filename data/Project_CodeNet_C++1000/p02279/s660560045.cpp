#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int inf = 1000000000;

class tree{
public:
  int node;
  int depth = -1;
  int parent = -1;
  vector<int> child;
  tree(int n, int c){
    node = n;
    child.resize(c);
    for(int i=0; i<c; i++) cin >> child[i];
  }
  tree(){}

  bool operator<(const tree& r)const{
    return node < r.node;
  }
};

vector<tree> t;
void input(int n, int c){
  t[n].node = n;
  t[n].child.resize(c);
  for(int i=0; i<c; i++) cin >> t[n].child[i];
}
int getdepth(int pos, int depth){
  t[pos].depth = depth;
  for(int i=0; i<t[pos].child.size(); i++){
    getdepth(t[ t[pos].child[i] ].node, depth+1);
  }
  return 0;
}

string gettype(int node){
  if( t[node].parent == -1 ) return "root";
  else if( t[node].child.size() == 0 ) return "leaf";
  else return "internal node";
}

bool cl(tree l, tree r){
  return l.node < r.node;
}

int main(void) {

  int n;
  cin >> n;
  int a, b;
  t.resize(n);
  for(int i=0; i<n; i++){
    cin >> a >> b;
    // tree tmp(a, b);
    input(a, b);
    // t.push_back(tmp);
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<t[ t[i].node ].child.size(); j++){
      t[ t[ t[i].node ].child[j] ].parent = t[t[i].node].node;
    }
  }
  for(int i=0; i<n; i++){
    int now = t[i].node;
  }

  int r = -1;
  for(int i=0; i<n; i++) if( t[t[i].node].parent == -1 ) r = t[i].node;
  getdepth(r, 0);

  sort(t.begin(), t.end());

  for(int i=0; i<n; i++){
    printf("node %d: parent = %d, depth = %d, ", t[i].node, t[t[i].node].parent, t[t[i].node].depth);
    // cout << t[i].node<<gettype(t[t[i].node].node) << ", ";
    cout << gettype(t[i].node) << ", ";
    cout << "[";
    for(int j=0; j<t[i].child.size(); j++){
      if( j == t[i].child.size()-1 ) cout << t[i].child[j];
      else cout << t[i].child[j] << ", ";
    }
    cout << "]\n";
  }



  return 0;
}

// EOF