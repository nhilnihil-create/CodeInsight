#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  double w,h,x,y;
  cin >> w >> h >> x >> y;
  double ans = w*h / 2;
  int flag = 0;
  if (x*2 == w && y*2 == h) flag = 1;
  else flag = 0;
  cout << ans << " " << flag << endl;
  return 0;
}
