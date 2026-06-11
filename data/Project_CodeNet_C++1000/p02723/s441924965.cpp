#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  if(s.at(2) == s.at(3) && s.at(4) == s.at(5)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
