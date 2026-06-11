#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  long long int ans = 1;
  for (int i = 0; i < N; i++)
  {
    int64_t a = A.at(i), prev = ans;
    ans = prev * a;
    if (ans > 1000000000000000000 || __builtin_smulll_overflow(prev, a, &ans))
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}