#include <bits/stdc++.h>
using namespace std;

void prime_factorize(int64_t N, set<int64_t> &pf)
{
  vector<pair<int64_t, int64_t>> res;
  for (int64_t a = 2; a * a <= N; a++)
  {
    if (N % a != 0)
      continue;
    int64_t ex = 0;
    while (N % a == 0)
    {
      ex++;
      N /= a;
    }
    pf.insert(a);
  }
  if (N != 1)
    pf.insert(N);
}

int main()
{
  int64_t A, B, ans = 1;
  set<int64_t> pfa, pfb;
  cin >> A >> B;
  prime_factorize(A, pfa);
  prime_factorize(B, pfb);
  for (auto n : pfa)
  {
    if (pfb.count(n))
      ans++;
  }
  cout << ans << endl;
}
