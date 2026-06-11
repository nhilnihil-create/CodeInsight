#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,a,b) for(i=a; i<b; ++i)
#define rep(i,n) REP(i,0,n)

int board[10001];

int pop(int x) {
  int n = 0;
  while(x != 0) {
    n = n + 1;
    x = x & (x-1);
  }
  return n;
}

int main() {
  int n,i,j,k,r,c;
  while(scanf("%d %d", &r, &c), r|c) {
    memset(board, 0, sizeof(board));
    rep(i,r) {
      rep(j,c) {
	scanf("%d", &k);
	if(k) board[j] |= (1<<i);
      }
    }

    int ans = 0;
    rep(i,(1<<r)) {
      int t = 0,tt;
      rep(j,c) {
	tt = pop(board[j] ^ i);
	t += max(tt, r-tt);
      }
      ans = max(ans, t);
    }
    printf("%d\n", ans);
  }
}