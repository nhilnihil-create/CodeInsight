#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  long long n, k;

  cin >> n >> k;

  long long waru = 1000000007;

  long long ans = 0;

  for (long long i = k; i <= n + 1; i++)
  {
    long long low = i * (i - 1) / 2;
    long long high = (2 * n - i + 1) * i / 2;
    long long dif = high - low + 1;
    ans = (ans+dif)%waru;

  }
  cout << ans;
}
