#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,K=0; cin >> A >> B;
  for(int i=1; i<1000000000; i++) {
    if(abs(A-i)==abs(B-i)) {
      K = i;
      break;
    }
  }
  if(K==0) cout << "IMPOSSIBLE" << endl;
  else cout << K << endl;
}