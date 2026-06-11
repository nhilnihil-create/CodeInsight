#include<bits/stdc++.h>
using namespace std;

signed main() {
  string S;
  cin >> S; 
  for(int i=0; i<S.size()-1; i++) {
    if(S[i] == S[i+1]) {
      puts("Bad"); return 0;
    }
  }
  puts("Good");
}
