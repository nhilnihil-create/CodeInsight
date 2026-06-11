#include<iostream>
#include<algorithm>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  int a[A], b[B], x[M], y[M],c[M];
  rep(i,0,A-1) cin >> a[i];
  rep(i,0,B-1) cin >> b[i];
  rep(i,0,M-1) cin >> x[i] >> y[i] >> c[i];
  int ans = 1<<20;
  rep(i,0,M-1) ans = min(ans, a[x[i]-1] + b[y[i]-1] - c[i]);
  int mina = *min_element(a, a+A);
  int minb = *min_element(b, b+B);
  ans = min(ans, mina + minb);
  cout << ans << endl;
  return 0;
}
