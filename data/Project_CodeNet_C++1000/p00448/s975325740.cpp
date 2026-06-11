#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <numeric>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int R, C;
int t[12][10010];

int solve() {
  int mxCnt = 0;
  // 2^10 * 10^4 * 10
  // 1000 * 10^5
  // ひっくり返す 行 を全て試す
  for (int S = 0; S < (1<<R); ++S) {
    int curCnt = 0;
    // i 列に着目する
    for (int i = 0; i < C; ++i) {
      // ひっくり返す場合
      int rCnt = 0;
      for (int j = 0; j < R; ++j)
        if (((S >> j & 1) + t[j][i] + 1) % 2 == 0)
          ++rCnt;
      // ひっくり返さない場合
      int nrCnt = 0;
      for (int j = 0; j < R; ++j)
        if (((S >> j & 1) + t[j][i]) % 2 == 0)
          ++nrCnt;
      curCnt += max(rCnt, nrCnt);
    }
    mxCnt = max(mxCnt, curCnt);
  }
  return mxCnt;
}

int main() {
  while (scanf("%d%d", &R, &C), R | C) {
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        scanf("%d", t[i] + j);
    printf("%d\n", solve());
  }
  return 0;
}