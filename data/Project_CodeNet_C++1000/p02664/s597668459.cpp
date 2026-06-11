#include <bits/stdc++.h>
using namespace std;
int Count (string S) {
  int ret = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == 'D') ret++;
  }
  for (int i = 0; i < S.size() - 1; i++) {
    if (S.at(i) == 'P' && S.at(i + 1) == 'D') ret++;
  }
  return ret;
}

  
  
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
	if (s.at(i) == '?')  s.at(i) = 'D';
  }
  cout << s << endl;
  
  
}
  