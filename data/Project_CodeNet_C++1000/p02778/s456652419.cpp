#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  for(int i = 0; i < (int)s.size(); i++) {
    s.at(i) = 'x';
  }
  for(int i = 0; i < (int)s.size(); i++) {
    cout << s.at(i);
  }
  cout << endl;
  return 0;
}