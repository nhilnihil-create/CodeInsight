#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int w,h,x,y;
  cin >> w >> h >> x >> y;
  printf("%lf %d\n", double(w)*double(h)/2, x + x == w && y + y == h);
}
