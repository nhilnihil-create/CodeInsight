#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> graph;

int dist[110000];

int main() {
  int n;
  cin >> n;
  graph g(n);
  vi a(n), b(n);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  int k = 0;
  int root;
  rep(i,n) {
    int s = g[i].size();
    k = max(k,s);
    if(k==s) root = i;
  }
  rep(i,n) dist[i] = -1;
  vi color_of_ver(n);
  queue<int> q;
  q.push(root);
  color_of_ver[root] = -1;
  dist[root] = 0;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    int c = 0;
    for(auto u : g[v]) {
      if(dist[u]!=-1) continue;
      if(c==color_of_ver[v]) c++;
      dist[u] = dist[v]+1;
      color_of_ver[u] = c;
      c++;
      q.push(u);
    }
  }
  cout << k << endl;
  rep(i,n-1) {
    int m;
    if(dist[a[i]]<dist[b[i]]) m = color_of_ver[b[i]];
    else m = color_of_ver[a[i]];
    cout << m+1 << endl;
  }
  return 0;
}