#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;

int main() {
  int n;
  string s,t,ans = "";
  cin >> n >> s >> t;
  rep(i,n) {
    ans = ans + s.at(i) + t.at(i);
  }
  cout << ans << endl;
}
