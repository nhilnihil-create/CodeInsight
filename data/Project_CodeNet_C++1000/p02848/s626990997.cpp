#include <bits/stdc++.h>
using namespace std; 
int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i < S.size(); i++) {
    for(int j = 0; j < 26; j++) {
      if(S.at(i) ==s.at(j)) {
        if(j + N > 25) {cout << s.at(j + N - 26);}
        else {cout << s.at(j + N);}
      }
    }
  }
  cout << endl;
}