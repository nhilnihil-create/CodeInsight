#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<long long> A(N), B(N);
  for(int i = 1; i < N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  int k = 0;
  
  for(int i = 0; i < N; i++) {
    for(int j = k; j < N; j++) {
      if(A.at(j) == i + 1) B.at(i)++;
      else if(A.at(j) > i + 1) break;
    }
    k += B.at(i);
  }
  
  for(int i = 0; i < N; i++) {
    cout << B.at(i) << endl; 
  }
  
}