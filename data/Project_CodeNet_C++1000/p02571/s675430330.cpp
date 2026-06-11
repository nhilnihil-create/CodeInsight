#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int ans = 1000;
  for(int i = 0; i < S.size() - T.size() + 1; i++) {
    int count = 0;
    for(int j = i; j < i + T.size(); j++) {
      if(S.at(j) != T.at(j - i)) {
        count++;
      }
    }
    if(count < ans) {
      ans = count;
    }
  }
  cout << ans << endl;
}