#include <bits/stdc++.h>
using namespace std;
  
int main() {
  long long N;
  cin >> N;
  long long X = 0;
  
  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (i == 0){
      B.at(i) = X;
    }
    else if (i % 2 == 0){
      X += A.at(i-1) - A.at(i-2);
    }
    B.at(i) = X;
  }
  
  X = (A.at(N-1) - B.at(N-1))/2;
  
  for (int i = 0; i < N; i++) {
    cout << X*2;
    X = A.at(i) - X;
    if (i == N-1){
      cout << endl;
    }
    else {
      cout << ' ';
    }
  }
}
  