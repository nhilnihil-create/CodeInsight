#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x,y;
  cin >> x >> y;
  ll a = 2 * x - y / 2;
  ll b = y / 2 - x;
  ll result = 2 * a + 4 * b;
  if(result == y && a + b == x && a >= 0 && b >= 0) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}
