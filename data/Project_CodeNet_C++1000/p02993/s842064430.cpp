#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  bool flag = false;
  for(int i = 1; i < s.size(); i++) {
    if(s[i-1] == s[i]) flag = true;
  }
  if(flag) cout << "Bad" << endl;
  else cout << "Good" << endl;
}