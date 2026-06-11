#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S,T; cin >> S >> T;
  int N = S.size();
  bool ans = true;
  for(int i=0; i<N; i++) {
    if(S[i] != T[i]) ans=false;
  }
  if(ans==true) cout << "Yes" << endl;
  if(ans==false) cout << "No" << endl;
}