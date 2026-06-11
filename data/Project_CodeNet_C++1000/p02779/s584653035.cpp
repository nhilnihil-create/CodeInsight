#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long> A(N);
  for (int i =0; i<N; i++) cin >> A.at(i);
  
  bool check = false;
  sort(A.begin(),A.end());
  for (int i =0; i<N-1; i++) {
    if (A.at(i) == A.at(i + 1) ) {
      check = true;
      break;
    }
  }
  if (check) {
    cout << "NO" << endl;
  } else {  
    cout << "YES" << endl;
  }
}