#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans = 0;
  string S;
  cin >> N >> S;
  
  for(int i = 0; i < N-2; i++) {
    if(S.at(i)=='A' && S.at(i+1)=='B' && S.at(i+2)=='C') ans++;
  }
  
  cout << ans << endl;
  
}