#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  long long sum = 0;
  vector<long> A(N+1,0); for (int i = 0; i < N+1; i++) cin >> A.at(i);
  vector<long> B(N,0); for (int i = 0; i < N; i++) cin >> B.at(i);
  
  for (int i = 0; i < N; i ++){
    if (A.at(i) + A.at(i+1) <= B.at(i)) {
      sum += A.at(i) + A.at(i+1);
      A.at(i) = 0;
      A.at(i+1) = 0;
    }else{
      sum += B.at(i);
      if (A.at(i) <= B.at(i)) A.at(i+1) = A.at(i+1) - (B.at(i) - A.at(i));
      A.at(i) = 0;
    }
  }

  cout << sum << endl;
}