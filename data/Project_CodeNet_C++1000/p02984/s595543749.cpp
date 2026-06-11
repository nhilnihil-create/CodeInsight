#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  vector<long long> A;
  long long sum = 0, sum2 = 0;
  
  for (int i = 0; i < N; i++) {
    long long inA;
    
    cin >> inA;
    
    sum += inA * (i % 2 == 0 ? 1 : -1);
    
    A.push_back(inA);
  }
  
  long long X = sum;
  
  cout << X;
  
  for (int i = 0; i < N - 1; i++) {
    X = 2 * A[i] - X;
    
    cout << " " << X;
  }
  
  return 0;
}