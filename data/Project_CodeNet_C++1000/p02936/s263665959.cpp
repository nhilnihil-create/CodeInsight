#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
vector<int> Graph[210000];
vector<int> Depth[210000];
vector<int> Deep(210000);
vector<int> Parent(210000);
vector<int> child[210000];
int root;
void BFS() {
  for (int i = 0; i < (int)Deep.size(); i++) {
    Deep[i] = 999999;
  }
  priority_queue<P, vector<P>, greater<P>> Q;
  Q.push(make_pair(0,root));
  Depth[0].push_back(root);
  Deep[root] = 0;
  while (!Q.empty()) {
    P p = Q.top();
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
  int N,Q;
  cin >> N >> Q;
  
  int ans[N];
  for (int i = 0; i < N; i++) {
    ans[i] = 0;
  }
  for (int i = 0; i < N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }
  root = 0;
  
  BFS();

  for (int i = 0; i < Q; i++) {
    int p,x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  for (int i = 0; i < N-1; i++) {
    for (int j = 0; j < (int)Depth[i].size(); j++) {
      for (int k = 0;  k < (int)child[Depth[i][j]].size(); k++) {
        ans[child[Depth[i][j]][k]] += ans[Depth[i][j]];
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}