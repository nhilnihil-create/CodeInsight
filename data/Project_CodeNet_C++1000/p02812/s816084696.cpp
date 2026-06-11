#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, n-2) {
    if(s.at(i) == 'A') {
      if(s.at(i+1) == 'B') {
        if(s.at(i+2) == 'C') {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}