#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX 200005
const llong mod = 1000000000 + 7;

int main()
{
  int K, N;
  int A[MAX];
  int tmp, ma = 0, total = 0;
  scanf("%d%d", &K, &N);

  // 差分は最後の要素と比較するため計算しない
  scanf("%d", &A[0]);
  // 差分の最大値を取得
  for (int i = 1; i < N; i++)
  {
    scanf("%d", &A[i]);
    ma = max(ma, A[i] - A[i - 1]);
  }
  // 最初の要素と最後の要素の差分を取得
  ma = max(ma, (K + A[0] - A[N - 1]));

  // 答え
  printf("%d\n", K - ma);

  return 0;
}