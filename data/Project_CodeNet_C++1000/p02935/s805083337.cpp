#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V[i];
  }
  sort(V.begin(),V.end());
  double a = V[0];
  for (int i=0; i<N; i++) {
    
    a = (a + V[i])/2.0;
    
  }
  cout << a;
  return 0;
}