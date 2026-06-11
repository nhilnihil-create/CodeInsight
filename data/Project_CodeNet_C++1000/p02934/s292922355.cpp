#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  double S, T;
  
  S = 0.0;
  for (int i = 0; i < N; i++) {
    S = S + 1.0/A.at(i);
  }
    
  T = 1.0/S;
    
  cout << fixed << setprecision(10);
  cout << T << endl;
 
}
