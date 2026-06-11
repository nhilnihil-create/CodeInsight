#include<iostream>
#include<algorithm>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  int a[A], b[B];
  rep(i,0,A-1) cin >> a[i];
  rep(i,0,B-1) cin >> b[i];
  int mina = *min_element(a, a+A);
  int minb = *min_element(b, b+B);
  int ans = mina + minb;
  rep(i,0,M-1) {
    int x, y, c;
    cin >> x >> y >> c; x--; y--;
    ans = min(ans, a[x] + b[y] - c);
  }
  cout << ans << endl;
  return 0;
}
