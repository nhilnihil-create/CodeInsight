#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = (s); i < (n); i++)

struct Node { int parent, left, right; };
Node T[100001];
int depth[100001];

void rec(int u, int p) {
  depth[u] = p;
  if(T[u].right != -1) rec(T[u].right, p);
  if(T[u].left != -1) rec(T[u].left, p+1);
}

void print(int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << depth[u] << ", ";
  if(T[u].parent == -1) cout << "root";
  else if(T[u].left == -1) cout << "leaf";
  else cout << "internal node";
  cout << ", [";
  for(int i = 0, c = T[u].left; c != -1; i++, c = T[c].right) {
    if(i) cout << ", ";
    cout << c;
  }
  cout << "]" << "\n";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  int n, v, k, c, l, r;
  cin >> n;
  rep(i, 0, n) T[i].parent = T[i].left = T[i].right = -1;
  rep(i, 0, n) {
    cin >> v >> k;
    rep(j, 0, k) {
      cin >> c;
      if(j == 0) T[v].left = c;
      else T[l].right = c;
      l = c;
      T[c].parent = v;
    }
  }
  rep(i, 0, n) {
    if(T[i].parent == -1) r = i;
  }
  rec(r, 0);
  rep(i, 0, n) print(i);
}
