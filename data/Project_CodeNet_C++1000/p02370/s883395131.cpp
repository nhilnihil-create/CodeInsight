#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int color[10000];
int indeg[10000];

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i=0;i<m;++i){
    int a,b;
    cin >> a >> b;
    g[a].emplace_back(b);
    indeg[b]++;
  }

  vector<int> out;
  for(int u=0;u<n;++u){
    if(indeg[u]==0&&color[u]==0){
      queue<int> q;
      q.push(u);
      color[u] = 1;
      while(!q.empty()){
        auto v = q.front();q.pop();

        out.push_back(v);
        for(const auto &w:g[v]){
          indeg[w]--;
          if(indeg[w]==0&&color[w]==0){
            color[w] = 1;
            q.push(w);
          }
        }
      }
    }
  }
  for(auto o:out) cout << o << endl;
}