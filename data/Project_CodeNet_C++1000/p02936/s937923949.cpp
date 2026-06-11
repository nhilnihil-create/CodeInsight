#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  queue<int> q;
  q.push(0);
  while (!q.empty()){
    int v = q.front();
    q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        q.push(w);
      }
    }
  }
  vector<int> A(N, 0);
  for (int i = 0; i < Q; i++){
    int p, x;
    cin >> p >> x;
    p--;
    A[p] += x;
  }
  queue<int> q2;
  q2.push(0);
  while (!q2.empty()){
    int v = q2.front();
    q2.pop();
    for (int w : c[v]){
      A[w] += A[v];
      q2.push(w);
    }
  }
  for (int i = 0; i < N; i++){
    cout << A[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}