#include <bits/stdc++.h>
using namespace std;
 
int main () {
  char C;
  cin >> C;
  string memo = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++){
    if (C == memo.at(i)) {
      cout << memo.at(i + 1) << endl;
      break;
    }
  }
}