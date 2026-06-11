#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool res = true;
  for (int i = 0; i < S.size(); ++i) {
    if (i % 2 == 0 && S[i] == 'L') res = false;
    if (i % 2 == 1 && S[i] == 'R') res = false;
  }
  if (res) puts("Yes");
  else puts("No");
}