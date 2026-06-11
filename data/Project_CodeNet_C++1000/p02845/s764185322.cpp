#include <bits/stdc++.h>
#define INF 10000000000
using namespace std;

int main()
{
  long long N, a;
  cin >> N;
  long long ans = 1;
  vector<long long> cnt(3, 0);
  for (long long i = 0; i < N; ++i)
  {
    cin >> a;
    long long temp = 0;
    bool first_time = true;
    for (long long j = 0; j < 3; ++j)
    {
      if (cnt.at(j) == a)
      {
        temp += 1;
        if (first_time)
        {
          first_time = false;
          cnt.at(j) = a + 1;
        }
      }
    }
    ans = (ans * temp) % 1000000007;
  }
  cout << ans % 1000000007 << endl;
}
