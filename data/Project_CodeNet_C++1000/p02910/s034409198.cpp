#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  bool flag = true;
  rep(i, s.size()) {
    if(i % 2 == 0 && s.at(i) != 'R' && s.at(i) != 'U' && s.at(i) != 'D') flag = false;
    else if(i % 2 != 0 && s.at(i) != 'L' && s.at(i) != 'U' && s.at(i) != 'D') flag = false;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
  