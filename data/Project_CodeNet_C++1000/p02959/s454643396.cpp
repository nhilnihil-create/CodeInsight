#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N+1), B(N);
  rep(i, N+1) cin >> A.at(i);
  rep(i, N) cin >> B.at(i);
  long long mon_count = 0;
  rep(i, N) {
    if (A.at(i) < B.at(i)) {
      mon_count += A.at(i);
      B.at(i) -= A.at(i);
      A.at(i) = 0;
      if (A.at(i+1) >= B.at(i)) { 
        mon_count += B.at(i);
        A.at(i+1) -= B.at(i);
      }
      else {
        mon_count += A.at(i+1);
        A.at(i+1) = 0;
      }
    }
    else {
      A.at(i) -= B.at(i);
      mon_count += B.at(i);
    }
  }
  cout << mon_count << endl;
}