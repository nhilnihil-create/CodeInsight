#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int N,K;
vector<int> Graph[110000];
vector<int> Depth[110000];
vector<int> Deep(110000);
vector<int> Parent(110000);
vector<int> child[110000];
vector<int> cnt(110000);
int root;
void BFS() {
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
  cin >> N >> K;
  ll ans = (ll)K;
  for (int i = 0; i < N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }
  for (int i = 0; i < N; i++) Deep[i] = 99999999;
  for (int i = 0; i < N; i++) {
    if ((int)Graph[i].size() == 1) {
      root = i;
      break;
    }
  }

  BFS();

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < (int)Depth[i].size(); j++) {
      int s = Depth[i][j];
      ll l;
      if (i == 1) {
        l = K - 1 - cnt[Parent[s]];
        cnt[Parent[s]]++;
      } else {
        l = K - 2 - cnt[Parent[s]];
        cnt[Parent[s]]++;
      }
      ans *= l;
      ans %= Mod;
    }
  }
  cout << ans << endl;
  return 0;
}