#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> edge;

void dfs(int x, int y, vector<vector<int>> &data) {
  int a;
  if(y != -1) {
    a = edge[make_pair(min(x, y), max(x, y))];
  }
  else {
    a = 100010;
  }
  int pass = 0;
  for(int i = 0; i < data.at(x).size(); i++) {
    if(data.at(x).at(i) == y) {
      pass = 1;
      continue;
    }
    else {
      if(i + 1 - pass < a) {
        int c = min(x, data.at(x).at(i));
        int d = max(x, data.at(x).at(i));
        edge.at(make_pair(c, d)) = i + 1 - pass;
        dfs(data.at(x).at(i), x, data);
      }
      else {
        int c = min(x, data.at(x).at(i));
        int d = max(x, data.at(x).at(i));
        edge.at(make_pair(c, d)) = i + 2 - pass;
        dfs(data.at(x).at(i), x, data);
      }
    }
  }
}
        
int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> call(N - 1);
  vector<vector<int>> data(N);
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    data.at(a - 1).push_back(b - 1);
    data.at(b - 1).push_back(a - 1);
    edge[make_pair(a - 1, b - 1)] = 0;
    call.at(i) = make_pair(a - 1, b - 1); 
  }
  dfs(0, -1, data);
  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < data.at(i).size(); j++) {
      if(i < data.at(i).at(j)) {
        if(edge[make_pair(i, data.at(i).at(j))] > ans) {
          ans = edge[make_pair(i, data.at(i).at(j))];
        }
      }
    }
  }
  cout << ans << endl;
  for(int i = 0; i < N - 1; i++) {
    cout << edge[call.at(i)] << endl;
  }
}