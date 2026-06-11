#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;

bool f(string s) {
  string sr = s;
  //cout << sr << endl;
  reverse(sr.begin(), sr.end());
  //cout << sr << endl;
  if (sr == s) return true;
  else return false;
}

int main() {
  string s;
  cin >> s;
  if (!f(s)) {
    cout << "No" << endl;
    return 0; 
  }
  string s2 = s.substr(0, s.size()/2);
  if (!f(s2)) {
    cout << "No" << endl;
    return 0; 
  }
  cout << "Yes" << endl;
  return 0;
}