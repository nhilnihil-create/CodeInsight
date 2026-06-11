#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  double m=(double)(W*H)/2;
  cout << m << " ";
  if (x*2==W && y*2==H) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}