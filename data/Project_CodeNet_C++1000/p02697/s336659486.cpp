#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
int n, m;

void solve() {
  cin>>n>>m;
  int x=m-m/2,y=m/2;
  rep(i,1,x)printf("%d %d\n",i,x*2-i+1);
  rep(i,1,y)printf("%d %d\n",x*2+i,x*2+y*2-i+2);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}
