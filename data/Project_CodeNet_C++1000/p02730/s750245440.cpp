#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool solve(string S) {
  string T = S;
  reverse(T.begin(), T.end());
  if (S != T) return false;
  
  S = S.substr(0, S.size()/2);
  T = S;
  reverse(T.begin(), T.end());
  if (S != T) return false;
  
  return true;
}

int main() {
  string S;
  cin >> S;
  if (solve(S)) puts("Yes");
  else puts("No");
}