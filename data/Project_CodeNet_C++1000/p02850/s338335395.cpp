#include<bits/stdc++.h>
#include<queue>
#include<map>
using namespace std;
pair<int, int> mp(int a, int b) {
  if (a > b) swap(a, b);
  return make_pair(a, b);
}
int main () {
  int N;
  cin >> N;
  vector<vector<int>>tree(N);
  map<pair<int, int>, int>F;
  for (int i = 0; i < N - 1; i ++) {
    int a, b;
    cin >> a >> b;
    a --;
    b --;
    tree[a].push_back(b);
    tree[b].push_back(a);
    F[make_pair(a, b)] = i;
  }
  F[make_pair(-1, 0)] = N - 1;
  vector<int>cl(N, 0);
  vector<int>par(N);
  par[0] = -1;
  queue<int>que;
  que.push(0);
  int K = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    int c = 1;
    for (int i = 0; i < (int)tree[u].size(); i ++) {
      int v = tree[u][i];
      //cout << v << endl;
      if (cl[F[mp(u, v)]] == 0) {
        //cout << 'r' << ' ';
        if (cl[F[mp(u, par[u])]] == c) c ++;
        cl[F[mp(u, v)]] = c;
        c ++;
        par[v] = u;
        que.push(v);
      }
    }
    //cout << c;
    if (K < c - 1) K = c - 1;
    //cout << endl;
  }
  //cout << endl;
  cout << K << endl;
  for (int i = 0; i < N - 1; i ++) cout << cl[i] << endl;
}

