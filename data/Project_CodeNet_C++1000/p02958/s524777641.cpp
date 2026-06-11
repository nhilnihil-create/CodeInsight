#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V[i];
  }
  
  int C=0;
  for (int i=0; i<N; i++) {
    if (V[i]!=i+1) {
      C++;
    }
  }
  if (C<=2) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}