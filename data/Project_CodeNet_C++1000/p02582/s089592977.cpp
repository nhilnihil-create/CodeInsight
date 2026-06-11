#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int sum = 0, rui = 0;
  for(int i = 0; i < 3; i++) {
    if(s[i] == 'R') rui++;
    else rui = 0;
    if(sum <= rui) sum = rui;
  }
  cout << sum << "\n";
}