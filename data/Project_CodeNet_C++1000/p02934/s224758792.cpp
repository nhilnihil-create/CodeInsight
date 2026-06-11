#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> V(N);
  double S=0;
  for (int i=0; i<N; i++) {
    cin >> V[i];
    S+=1/V[i];
  }
  cout << 1/S << endl;
  
}