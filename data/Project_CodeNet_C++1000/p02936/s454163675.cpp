#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
vector<bool> visited;

void dfs(vector<vector<int>>& graph, int start, vector<int>& ans) {
  visited[start] = true;
  if(graph[start].size() == 0) {
    return;
  }
  for(auto node: graph[start]) {
    //cout << start << " " <<  node << endl;
    if(visited[node]) {
      continue;
    }
    ans[node] += ans[start];
    dfs(graph, node, ans);
    visited[node] = true;
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>>graph(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    graph[a-1].push_back(b-1);
    graph[b-1].push_back(a-1);
  }
  vector<vector<int>>root(n);
  rep(i, n) {
    root[i].push_back(i);
  }
  visited = vector<bool>(n, false);
  
  //cout << endl;
  //rep(i, n) {
  //  rep(j, root[i].size()) {
  //    cout << root[i][j] << " ";
  //  }
  //  cout << endl;
  //}
  vector<int>ans(n, 0);
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    ans[p-1] += x;
  }
  dfs(graph, 0, ans);
  rep(i, n) {
    cout << ans[i];
    if(i == n-1) {cout << endl;}
    else {cout << " ";}
  }
  return 0;
}