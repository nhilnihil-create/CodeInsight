#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  for(int i = 0; i < N; i++) {
    if(A.at(i) % 2 != 0) A.at(i) = 1;
    else {
      if(A.at(i) % 3 == 0 || A.at(i) % 5 == 0) A.at(i) = 1;
      else A.at(i) = 0;
    }
  }
  
  int ans = 1;
    
  for(int i = 0; i < N; i++) {
//    cout << "A.at(" << i << ")" << A.at(i) << ", ";
      ans *= A.at(i);
//    cout << "ans(" << i << ")" << ans << ", ";
  }
  
  if(ans == 1) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
  
}