#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  if (N == 1){
    cout << 0 << endl;
    return 0;
  }
  

  vector<long long> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  
  vector<int> A(N-1,0);
  vector<int> B(N-1,0);
 
  for (int i = 0; i < N-1; i++) {
    if (H.at(i) >= H.at(i+1)){
      A.at(i) = 1;
    }
  }
  
  int count = 0;
  for (int i = 0; i < N-1; i++) {
    if (A.at(i) == 1 && i != N-2){
      count++;
    }
    else if (A.at(i) == 1 && i == N-2){
      count++;
      B.at(i) = count;
    }
    else {
      B.at(i) = count;
      count = 0;
    }
  }
  
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  cout << B.at(0) << endl;
}