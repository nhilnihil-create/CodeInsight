#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans = 1;
  cin >> N;
  vector<int64_t> A(N + 1), MA(N + 1), MI(N + 1);
  for (int i = 0; i <= N; i++)
  {
    cin >> A.at(i);
  }
  MA[N] = MI[N] = A[N];
  for (int i = N - 1; i >= 0; i--)
  {
    MI[i] = (MI[i + 1] + 1) / 2 + A[i];
    MA[i] = MA[i + 1] + A[i];
  }
  if (!(MI[0] <= 1 && 1 <= MA[0]))
  {
    cout << -1 << endl;
    return 0;
  }
  int64_t prev = 1;
  for (int i = 1; i <= N; i++)
  {
    ans += min((prev - A[i - 1]) * 2, MA[i]);
    prev = min((prev - A[i - 1]) * 2, MA[i]);
  }
  cout << ans << endl;
}