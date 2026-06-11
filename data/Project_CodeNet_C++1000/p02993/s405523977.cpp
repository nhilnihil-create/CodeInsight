#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool fla = false;

  for(int i = 0; i < s.size()-1; i++) {
    if(s.at(i) == s.at(i+1)) {
      fla = true;
    }
  }
  fla == true ? cout << "Bad" : cout << "Good";

}