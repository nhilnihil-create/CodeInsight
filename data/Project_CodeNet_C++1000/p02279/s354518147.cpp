#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <utility>

using namespace std;

typedef enum {ROOT, LEAF, INTR} LEAF_TYPE;
string lt2str(LEAF_TYPE lt){
  switch(lt){
  case ROOT:
    return "root";
  case LEAF:
    return "leaf";
  case INTR:
    return "internal node";
  default:
    return "?";
  }
}

void dfs(int node, vector<int>& d, int depth, const vector<vector<int> > & ch){
  const vector<int>& childs = ch[node];
  d[node] = depth;
  for (int child : childs){
    dfs(child, d, depth+1, ch);
  }
}

int main(){
  int n; // 1..100000
  cin >> n;

  vector<int> v(n);
  vector<vector<int> > ch(n);
  vector<int> p(n, -1); //parent
  for(int i=0;i<n;++i){
    int id;
    cin >> id;
    int k;
    cin >> k;
    for(int j=0; j<k; ++j){
      int child;
      cin >> child;
      ch[id].push_back(child);
      p[child] = id;
    }
  }

  const int root_id = find(p.begin(), p.end(), -1) - p.begin();

  vector<int> d(n, -1);
  //dfs
  dfs(root_id, d, 0, ch);

  vector<LEAF_TYPE> l(n);
  for(int i=0; i<n; ++i){
    if(ch[i].size() == 0){
      l[i] = LEAF;
    }
    else{
      l[i] = INTR;
    }
  }
  l[root_id] = ROOT;

  //node 0: parent = -1, depth = 0, root, [1, 4, 10]

  for(int i=0; i<n; ++i){
    cout << "node " << i << ": "
	 << "parent = " << p[i] << ", "
	 << "depth = " << d[i] << ", "
	 << lt2str(l[i]) << ", "
	 << "[";
    for(int j=0; j<ch[i].size(); ++j){
      cout << (j==0 ? "": ", ") << ch[i][j];
    }
    cout << "]"
	 << endl;
    
  }


  
  //cout  << endl;
  return 0;
}