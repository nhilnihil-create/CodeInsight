#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; string s;
  cin >> n >> s;
  int t = s.size();
  if(n == 1) {
    cout << "No" << endl;
    return 0;
  }
  if(s.substr(0, t/2) == s.substr(t/2, t)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}