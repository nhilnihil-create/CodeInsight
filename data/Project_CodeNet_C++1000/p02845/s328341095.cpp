#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN = 1000010, MOD = 1000000007;
int64_t DP[MAXN]; // 人数iを取りうる色の数を記録

void init()
{
  for (int i = 0; i < MAXN; i++)
    DP[i] = 0;
}

int main()
{
  int64_t N, a, ans = 1;
  cin >> N;
  init();
  DP[0] = 3;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    ans = (ans * DP[a]) % MOD;
    DP[a]--;
    DP[a + 1]++;
  }
  cout << ans % MOD << endl;
}