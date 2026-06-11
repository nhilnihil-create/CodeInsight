#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h,a;
  cin >> h >> a;
  int cnt = 0;
  while (h > 0) {
    cnt++;
    h -= a;
  }
  cout << cnt << endl;
  return 0;
}
