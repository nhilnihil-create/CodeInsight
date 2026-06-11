#include <bits/stdc++.h>
using namespace std;
#define ROOT 0
#define INTERNAL 1
#define LEAF 2
#define REP(asd, fgh) for(int asd = 0; asd < fgh; asd++)

int n;

class Node{
  public:
  int p;
  int depth;
  string type;
};

vector<Node> ans;
vector< vector<int> > t;

void dfs(int ind, int prev, int depth){
  ans[ind].p = prev;
  ans[ind].depth = depth;
  if(t[ind].size() == 0 && ans[ind].type != "root"){
    ans[ind].type = "leaf";
    return;
  }
  for(int i = 0; i < t[ind].size(); i++){
    dfs(t[ind][i], ind, depth+1);
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  ans = vector<Node>(n);
  t = vector< vector<int> >(n, vector<int>(0));
  int root;
  REP(i, n){
    int id; cin >> id;
    ans[id].type = "internal node";
    int k;
    cin >> k;
    REP(j, k){
      int c; cin >> c;
      t[id].push_back(c);
    }
  }
  //ans[0].p = -1;
  //ans[0].depth = 0;
  vector<bool> used(n, false);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < t[i].size(); j++){
      used[ t[i][j] ] = true;
    }
  }
  for(int i = 0; i < n; i++){
    if(used[i] == false){
      root = i;
      break;
    }
  }
  ans[root].type = "root";
  dfs(root, -1, 0);

  for(int i = 0; i < n; i++){
    cout << "node " << i << ": parent = " << ans[i].p << ", depth = " << ans[i].depth << ", " << ans[i].type;
    cout << ", [";
    for(int j = 0; j < t[i].size(); j++){
      if(j != 0)
        cout << ", ";
      cout << t[i][j];
    }
    cout << "]" << endl;
  }

  return 0;
}