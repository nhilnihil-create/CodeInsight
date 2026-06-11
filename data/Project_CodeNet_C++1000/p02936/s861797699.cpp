#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
Graph G;


void dfs(int i, int p, vector<long long> &res){
  
  for(int j:G[i]) if(j != p){
     res[j] += res[i];
     dfs(j, i, res);
  }
}


int main(){
  long long N, Q;
  cin >> N >> Q;
  G.assign(N, vector<int>());
  
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
    
  }
  vector<long long> val(N, 0);
    
  for(int i=0; i<Q; i++){
    int p, x;
    cin >> p >> x;
    val[p-1] += x;
  }
  
  dfs(0, -1, val);
    
  for(auto v: val) cout << v << " ";
  cout << endl;
  
  
  return 0;
}