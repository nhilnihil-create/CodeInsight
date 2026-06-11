#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  string ans = "Yes";
  for (int i=0; i<(int)S.size(); i+=2) {
    if (S.at(i)=='L') {
      ans = "No";
      break;
    }
  }
  for (int i=1; i<(int)S.size(); i+=2) {
    if (S.at(i)=='R') {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}