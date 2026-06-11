#include <iostream>
using namespace std;

long long func(long long n, long long k)
{
  if(n * 2 <= k) return n;
  n -= n/k * k;
  return abs(n-k) < n ? abs(n-k) : n;
}

int main()
{
  long long n, k;
  cin >> n >> k;
  long long ans = func(n, k);
  cout << ans << endl;
}