#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int main()
{
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  // C++ MOD をとるような値になったときはlong longにする。
  // intが2**31-1 で2*10**9程度なので、 今回はぎり収まらないくらい
  vector<vector<long long>> DP(N + 1, vector<long long>(S + 1, 0));
  // 初期化 0 0 = 1
  DP[0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= S; j++)
    {
      if (j >= A[i])
        DP[i + 1][j] = DP[i][j] * 2 + DP[i][j - A[i]];
      else
        DP[i + 1][j] = DP[i][j] * 2;
      DP[i + 1][j] %= MOD;
    }
  }
  cout << DP[N][S] << endl;
}