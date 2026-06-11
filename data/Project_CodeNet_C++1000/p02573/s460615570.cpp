#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int dfs(int src, std::vector<bool>& visited, 
        std::unordered_map<int,std::vector<int>>& adj_list) 
{
  visited[src] = true;
  int cnt = 1;
  for (auto neighbor : adj_list[src]) {
    if (!visited[neighbor]) {
      cnt += dfs(neighbor, visited, adj_list);
    }    
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::unordered_map<int,std::vector<int>> adj_list{};
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }
  int max_size = 0;
  std::vector<bool> visited(n+1, false);
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      int size = dfs(i, visited, adj_list);
      max_size = max(size, max_size);
    }
  }
  std::cout << max_size << std::endl;
}