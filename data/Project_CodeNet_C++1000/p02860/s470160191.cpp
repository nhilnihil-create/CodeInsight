#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool flag = true;
  if(n % 2 != 0) flag = false;
  else rep(i, n/2) {
    if(s.at(i) != s.at((n/2) + i)) flag = false;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}