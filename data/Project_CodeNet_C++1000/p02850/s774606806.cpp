#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &c, vector<vector<pair<int, int>>> &E, int v = 0){
  int cnt = E[v].size();
  set<int> st;
  for (int i = 1; i <= cnt; i++){
    st.insert(i);
  }
  for (auto P : E[v]){
    int id = P.second;
    if (c[id] != -1){
      st.erase(c[id]);
    }
  }
  vector<int> color;
  for (int x : st){
    color.push_back(x);
  }
  for (auto P : E[v]){
    int w = P.first;
    int id = P.second;
    if (c[id] == -1){
      c[id] = color.back();
      color.pop_back();
      dfs(c, E, w);
    }
  }
}
int main(){
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(make_pair(b, i));
    E[b].push_back(make_pair(a, i));
  }
  vector<int> c(N - 1, -1);
  dfs(c, E);
  int K = 0;
  for (int i = 0; i < N - 1; i++){
    K = max(K, c[i]);
  }
  cout << K << endl;
  for (int i = 0; i < N - 1; i++){
    cout << c[i] << endl;
  }
}