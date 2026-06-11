#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long> A(N+1); for (int i =0; i<N+1; i++) cin >> A.at(i);
  vector<long> B(N); for (int i =0; i<N; i++) cin >> B.at(i);
  
  long count =0;
  for (int i =N; i>=1; i--) {
    if (B.at(i-1) >= A.at(i)) {
      count += A.at(i); B.at(i-1) -= A.at(i); A.at(i) =0;
    } else {
      count += B.at(i-1); A.at(i) -= B.at(i-1); B.at(i-1) =0;
    }
    if (B.at(i-1) >= A.at(i-1)) {
      count += A.at(i-1); B.at(i-1) -= A.at(i-1); A.at(i-1) =0;
    } else {
      count += B.at(i-1); A.at(i-1) -= B.at(i-1); B.at(i-1) =0;
    }
  }
  if (B.at(0) >= A.at(0)) {
    count += A.at(0); 
  } else {
    count += B.at(0);
  }
  cout << count << endl;
}