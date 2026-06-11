#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, d, a;
  cin >> N >> K;
  vector<int> V(N,1);
  for (int i=0; i<N; i++) {
    cin >> d;
    for (int j=0; j<d; j++) {
      cin >> a;
      V.at(a-1) = 0;
    }
  }
  
  int C=0;
  for (int i=0; i<N; i++) {
    if (V.at(i)) {
      C++;
    }
  }
  cout << C << endl;
}