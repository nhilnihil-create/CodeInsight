#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> circle(n);
  rep(i,n) {
    cin >> circle.at(i);
  }
  sort(circle.begin(),circle.end(),greater<int>());
  ll ans = 0;
  ans += circle[0];
  circle.erase(circle.begin());
  rep(i,n - 2) {
    ans += circle[0];
    if(i % 2 & 1) circle.erase(circle.begin());
  }
  cout << ans << endl;
  return 0;
}
