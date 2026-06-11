#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 200001

int main()
{
  int N;
  int A[MAX], B[MAX];
  llong K;
  scanf("%d", &N);
  scanf("%lld", &K);

  // 配列の初期化
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
    B[i] = 0;
  }

  // サイクルのスタートを見つける
  // Biがすでに訪れられていたらそれがサイクルのスタート
  llong startIndex = 0;
  llong i = 1;
  while (1)
  {
    if (B[i - 1])
    {
      startIndex = i;
      break;
    }
    B[i - 1] = 1;
    i = A[i - 1];
  }

  // startにいたるまでの手数を見つける
  llong I = 1;
  llong startCnt = 0;
  while (startIndex != I)
  {
    I = A[I - 1];
    startCnt++;
  }

  // サイクルの長さを見つける
  // サイクルの始まりからスタートして戻るまでの回数
  llong cnt = 1;
  while (1)
  {
    i = A[i - 1];
    if (startIndex == i)
    {
      i = startIndex;
      break;
    }
    cnt++;
  }
  if (startCnt > K)
  {
    i = 1;
    for (int j = 0; j < K; j++)
    {
      i = A[i - 1];
    }
    printf("%d\n", i);
    return 0;
  }

  K -= startCnt;
  int mod = K % cnt;

  for (int j = 0; j < mod; j++)
  {
    i = A[i - 1];
  }

  printf("%d", i);

  return 0;
}