#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;

  int ans;
  if (N % 1000 == 0) {
    ans = 0;
  }
  else {
    ans = 1000 - (N % 1000);
  }
  cout << ans << endl;
  return 0;
}