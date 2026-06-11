#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S;
  cin >> N;
  vector<int> W(N), M(N+1,0);
  for (int i=0; i<N; i++) {
    cin >> W[i];
    S+=W[i];
    M[i+1]+=M[i]+W[i];
  }
  int m=10000000;
  for (int i=0; i<=N; i++) {
    m=min(m, abs(S-2*M[i]));
  }
  cout << m << endl;
  
}
