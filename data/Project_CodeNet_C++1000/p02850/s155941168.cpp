#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
vector<int> Graph[110000];
vector<P> lis[110000];
vector<int> Depth[110000];
vector<int> Deep(110000);
vector<int> Parent(110000);
vector<int> child[110000];
vector<int> color(110000);
vector<int> ans(110000);
int root = 0;
void BFS() {
  for (int i = 0; i < (int)Deep.size(); i++) {
    Deep[i] = 999999;
  }
  queue<P> Q;
  Q.push(make_pair(0,root));
  Depth[0].push_back(root);
  Deep[root] = 0;
  while (!Q.empty()) {
    P p = Q.front();
    Q.pop();
    for (int i = 0; i < (int)Graph[p.S].size(); i++) {
      if (Deep[Graph[p.S][i]] > p.F + 1) {
        Q.push(make_pair(p.F+1,Graph[p.S][i]));
        Deep[Graph[p.S][i]] = p.F + 1;
        Depth[p.F+1].push_back(Graph[p.S][i]);
        Parent[Graph[p.S][i]] = p.S;
        child[p.S].push_back(Graph[p.S][i]);
      }
    }
  }
}
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    lis[a].emplace_back(b,i);
    lis[b].emplace_back(a,i);
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  BFS();
  
  color[0] = 0;
  for (int i = 0; i < N-1; i++) {
    for (int j = 0; j < (int)Depth[i].size(); j++) {
      int s = Depth[i][j];
      int num = 1;
      for (int k = 0; k < (int)child[s].size(); k++) {
        if (num == color[s]) num++;
        color[child[s][k]] = num;
        num++;
      }
    }
  }
  cout << *max_element(color.begin(),color.end()) << endl;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < (int)lis[i].size(); j++) {
      if (Deep[lis[i][j].F] < Deep[i]) {
        ans[lis[i][j].S] = color[i];
      }
    }
  }
  for (int i = 0; i < N-1; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}