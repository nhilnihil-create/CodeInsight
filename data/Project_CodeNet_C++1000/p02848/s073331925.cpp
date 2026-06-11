#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  string S;
  cin >> N >> S;
  string memo = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < 26; j++) {
      if (S.at(i) == memo.at(j)) {
        S.at(i) = memo.at(j + N);
        break;
      }
    }
  }
  cout << S << endl;     
}