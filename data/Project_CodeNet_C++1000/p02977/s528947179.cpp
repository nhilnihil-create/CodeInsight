#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef long double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc(); !isdigit(tmp); tmp = gc())
    key = (tmp == '-');
  for (; isdigit(tmp); tmp = gc()) 
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
  x = x < y ? y : x;
}

int n;
int main() {
  read(n);
  if (n <= 2) {
    puts("No");
    return 0;
  }
  int key = 1;
  for (int i = 1; i <= n; i <<= 1)
    if (i == n) key = 0;
  if (!key) {
    puts("No");
    return 0;
  }
  puts("Yes");
  rep (i, 1, 2) printf("%d %d\n", i, i+1);
  printf("3 %d\n", 1 + n);
  rep (i, 1, 2) printf("%d %d\n", i+n, i+1+n);
  for (int i = 4; i+1 <= n; i += 2) {
    printf("%d %d\n", i, i+n+1);
    printf("%d %d\n", i+n, i+1);
    printf("%d %d\n", i, n+1);
    printf("%d %d\n", i+1, n+1);
  }
  if (n % 2 == 0) {
    int v = n ^ 1;
    rep (i, 2, n-1) if ((v ^ i) < n && (v ^ i) > 1) {
      printf("%d %d\n", (i == 2 ? i + n : i), n);
      printf("%d %d\n", ((v ^ i) == 2 ? (v ^ i) + n : (v ^ i)), n + n);
      break;
    }
  }
  return 0;
}
