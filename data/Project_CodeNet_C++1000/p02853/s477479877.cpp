#include <bits/stdc++.h>
using namespace std;

int calc(int a) {
  if (a > 3) {
    return 0;
  } else if (a == 3) {
    return 100000;
  } else if (a == 2) {
    return 200000;
  } else {
    return 300000;
  }
}
int main() {
  int x, y;
  cin>>x>>y;
  int ans = calc(x) + calc(y);
  if (x == 1 && y == 1) {
    ans += 400000;
  }
  cout<<ans<<endl;
}