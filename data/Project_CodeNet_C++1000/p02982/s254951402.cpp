#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  for (int i=0; i<N; i++) {
    for (int j=0; j<D; j++) {
      cin >> X[i][j];
    }
  }
  
  int S;
  int C=0;
  int SS;
  for (int i=0; i<N-1; i++) {
    for (int j=i+1; j<N; j++) {
      S=0;
      for (int k=0; k<D; k++) {
        S+=(X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
      }
      SS=sqrt(S);
      if (S==SS*SS) {
        C++;
      }
    }
  }
  cout << C << endl;
}
