#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  string s;
  cin >> s;
  if (s[2] == s[3] && s[4] == s[5]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}