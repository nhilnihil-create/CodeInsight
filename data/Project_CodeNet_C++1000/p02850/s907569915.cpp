#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

vector<vector<pair<int, int>>> vec;
vector<int> edge;
vector<bool> vis;

void dfs(int node, int color){
  vis[node] = true;
  int c = 1;
  for(auto p : vec[node]){
    if(c == color) c++;
    if(vis[p.first]) continue;
    edge[p.second] = c;
    dfs(p.first, c);
    c++;
  }
} 

int main(){
  int n;
  cin >> n;
  rep(i, n) vec.push_back(vector<pair<int, int>>());
  rep(i, n-1) edge.push_back(0);
  rep(i, n) vis.push_back(false);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    vec[a].push_back(make_pair(b, i));
    vec[b].push_back(make_pair(a, i));
  }
  int k = 0;
  rep(i, n){
    k = max(k, (int)vec[i].size());
  }
  dfs(0, 1000000000);
  cout << k << endl;
  rep(i, n-1) cout << edge[i] << endl;
  return 0;
}