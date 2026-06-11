#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  rep(i,1,n+1) {
    ans += to_string(i).size() % 2;
  }
  cout << ans << endl;
  return 0;
}
