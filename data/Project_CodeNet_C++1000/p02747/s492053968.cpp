#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  if (s.size()%2) cout << "No" << endl;
  else {
    bool flag = 1;
    rep(i, s.size()/2) {
      if (s.at(2*i)=='h' && s.at(2*i+1)=='i') continue;
      flag = 0;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}