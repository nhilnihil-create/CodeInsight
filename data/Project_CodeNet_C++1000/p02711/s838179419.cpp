#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string n;
  cin >> n;
  bool flag = false;
  rep(i, 3) {
    if(n.at(i) == '7') flag = true;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}