#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  
  double sum = 0;
  for (int i = 0; i < N; i++){
    sum += 1.0 / A[i];
  }
  sum = 1.0 / sum; 
  
  cout << fixed << setprecision(10) << sum << endl;
}