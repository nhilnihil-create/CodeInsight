#if 0
はじめ、cを0~N-1で解いていたが、途中で0~Nで解くべきことに気が付いた。
また、c-C[i]>=0の時の、最小値の比較対象をc-C[j] (j <= i)の時も考えていたため解けなかったが、日を置いたら誤りに気が付いて解くことができた。
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M;
int C[25];
int cnt[25][50010];

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> C[i];
  sort(C, C+M);
  for (int i = 0; i < M; i++) {
    for (int c = 0; c <= N; c++) {
      if (i == 0)
        cnt[i][c] = c;
      else if (c == 0)
        cnt[i][c] = 0;
      else if (c-C[i] < 0)
        cnt[i][c] = cnt[i-1][c];
      else {
        cnt[i][c] = min(1 + cnt[i][c-C[i]], cnt[i-1][c]);
      }
    }
  }
  cout << cnt[M-1][N] << endl;
}

