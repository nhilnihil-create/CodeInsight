#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K; cin >> K;
  string S; cin >> S;
  int L = S.size();
  if(K >= L) cout << S << endl;
  else {
    for(int i=0; i<K; i++) {
      cout << S[i];
    }
    cout << "..." << endl;
  }
  return 0;
}