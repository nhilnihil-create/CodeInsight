#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  if(s.at(1) == 'B') cout << "ARC" << endl;
  else if(s.at(1) == 'R') cout << "ABC" << endl;
  return 0;
}