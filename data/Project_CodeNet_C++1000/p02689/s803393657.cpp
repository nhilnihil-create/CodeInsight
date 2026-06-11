#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N), C(N, 1);
  for (int i=0; i<N; i++) {
    cin >> H[i];
  }
  
  int a,b;
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    a--;
    b--;
    if (H[a]>H[b]) {
      C[b]=0;
    }
    else if (H[a]==H[b]) {
      C[b]=0;
      C[a]=0;
    }
    else {
      C[a]=0;
    }
  }
  
  int S=0;
  for (int i=0; i<N; i++) {
    S+=C[i];
  }
  cout << S << endl;
}