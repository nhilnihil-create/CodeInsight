#include <bits/stdc++.h>
using namespace std;;

int main() {
  int K,N; cin >> K >> N;
  vector<int> A(N); vector<int> interval(N);
  for (int i =0; i<N; i++) {
    cin >> A.at(i);
    if (i >= 1) interval.at(i) = A.at(i) - A.at(i-1);
  }
  interval.at(0) = K + A.at(0) - A.at(N-1);
  
  int maxInterval =0;
  for (int i =0; i<N; i++) {
    maxInterval = max(interval.at(i), maxInterval);
  }
  
  cout << K - maxInterval << endl;
}
  