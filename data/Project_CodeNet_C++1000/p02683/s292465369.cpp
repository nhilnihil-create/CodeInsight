#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> C(N);
  vector<vector<int>> A(N, vector<int>(M,0));
  for (int i=0; i<N; i++) {
    cin >> C[i];
    for (int j=0; j<M; j++) {
      cin >> A[i][j];
    }
  }
  int INF=10000000;
  int count, fin, mm=INF;
  
  for (int b=0; b < (1 << N); b++) {
    bitset<12> s(b);
    vector<int> V(M,0);
    count=0;
    fin=0;
    for (int i=0; i<N; i++) {
      if (s.test(i)) {
        count+=C[i];
        for (int j=0; j<M; j++) {
          V[j]+=A[i][j];
        }
      }
    }
    for (int i=0; i<M; i++) {
      if (V[i]<X) {
        fin=1;
        break;
      }
    }
    if (fin==1) {continue;}
    mm=min(mm, count);
  }
  if (mm==INF) {cout << -1 << endl;}
  else {cout << mm << endl;}
}