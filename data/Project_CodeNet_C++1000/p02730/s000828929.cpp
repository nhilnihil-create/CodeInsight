#include <bits/stdc++.h>
using namespace std;
int main() {
  string S; cin >> S;
  int N = S.size();
  int count =0;
  bool ans = true;
  
  for(int i=0; i< N/2; i++) {
    if(S.at(i) != S.at(N-1-i)) ans=false;
  }
  for(int i=0; i<N/2/2; i++) {
    if(S.at(i) != S.at(N/2-1-i)) ans=false;;
  }
    
  if(ans==true) cout << "Yes" << endl;
  else cout << "No" << endl;
    
}