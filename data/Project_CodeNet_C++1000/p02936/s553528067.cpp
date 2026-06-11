#include <vector>
#include <iostream>
using namespace std;
 
void dfs(const vector<vector<int>> &G, vector<int> &C,
         int v, int prev){
  for(auto v_ : G[v]){
    if(v_ == prev) continue;
    C[v_] += C[v];
    dfs(G,C,v_,v);
  }
}
 
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> G(N);
  for(int i = 1; i < N; ++i){
    int a, b;
    cin >> a >> b;
    --a,--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> C(N,0);
  for(int i = 0; i < Q; ++i){
    int p, x;
    cin >> p >> x;
    --p;
    C[p] += x;
  }
  dfs(G,C,0,-1);
  cout << C[0];
  for(int i = 1; i < N; ++i)
    cout << " " << C[i];
  cout << endl;
}