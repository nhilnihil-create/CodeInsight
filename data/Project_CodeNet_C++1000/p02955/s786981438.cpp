#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, s = 0;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  s = accumulate(A.begin(), A.end(), 0);
  set<int64_t> candidates;
  for (int64_t i = 1; i * i <= s; i++)
  {
    if (s % i == 0)
    {
      candidates.insert(i);
      candidates.insert(s / i);
    }
  }
  int64_t ans = 1;
  for (int64_t x : candidates)
  {
    int64_t need;
    {
      vector<int64_t> R(N);
      for (int i = 0; i < N; i++)
      {
        R[i] = A.at(i) % x;
      }
      sort(R.begin(), R.end());
      int64_t lsum = accumulate(R.begin(), R.end(), 0), rsum = 0;
      need = (1LL << 62);
      for (int i = N - 1; i >= 0; i--)
      {
        lsum -= R.at(i);
        rsum += x - R.at(i);
        need = min(need, max(lsum, rsum));
      }
    }
    if (need <= K)
      ans = max(ans, x);
  }
  cout << ans << endl;
}