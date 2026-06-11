#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  string ans = "Yes";
  for (int i=0; i<N; i++) {
    if (S.at(i) != S.at(N-1-i)) {
      ans = "No";
      break;
    }
  }
  
  for (int i=0; i<(N-1)/2; i++) {
    if (S.at(i) != S.at((N-1)/2-1-i)) {
      ans = "No";
      break;
    }
  }
  
  cout << ans << endl;
}