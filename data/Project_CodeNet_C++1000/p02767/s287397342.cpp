#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S=0;
  cin >> N;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V[i];
    S+=V[i];
  }
  
  S/=N;
  int m=0, n=0;
  
  for (int i=0; i<N; i++) {
    m+=(V[i]-S)*(V[i]-S);
  }
  S++;
  for (int i=0; i<N; i++) {
    n+=(V[i]-S)*(V[i]-S);
  }
  cout << min(m, n) << endl;
}