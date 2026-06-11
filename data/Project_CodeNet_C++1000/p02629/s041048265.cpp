#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll N;
  cin >> N;

  string ans;
  while (N > 0) {
    int c = (N - 1) % 26;
    ans = (char)('a' + c) + ans;
    N = (N - 1) / 26;
  }
  cout << ans << endl;
  return 0;
}