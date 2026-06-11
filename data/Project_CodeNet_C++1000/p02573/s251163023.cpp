#include <bits/stdc++.h>
using namespace std;
 
pair<int,int> root (int x, vector<int> &g, int t) {
  if (x == g.at(x)) {
    return pair<int,int>(x,t);
  }
  else {
    pair<int,int>  k = root(g.at(x),g,t+1);
    g.at(x) = k.first;
    return k;
  }
}
 
void connect(int a, int b, vector<int> &g) {
  pair<int,int> m = root(a,g,0);
  pair<int,int> n = root(b,g,0);  
  if (m.first != n.first) {
    if (m.second > n.second) {
      g.at(n.first) = m.first;   
    }
    else {
      g.at(m.first) = n.first;      
    }
  } 
  return;
}
 
int main() {
  
  int N, M;
  cin >> N >> M;
  
  vector<int> G(N);
  for (int i = 0; i < N; i++) {
    G.at(i) = i;
  }
  
  int A, B;
  
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    connect(A-1,B-1,G);
  }
  
  vector<int> G2(N,0);
  for (int i = 0; i < N; i++) {
    G2.at(root(i,G,0).first)++;
  }
  
  int X = 0;
  for (int i = 0; i < N; i++) {
    X = max(X,G2.at(i));
  }
  
  cout << X << endl;
  
  return 0;
}