#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b, int c)
{
  int m = __gcd(a, b), n = __gcd(b, c);
  return __gcd(m, n);
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, sum = 0;
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j++)
      for (int k = j; k <= N; k++){
	if (i == j && j == k)
	  sum += gcd(i, j, k);
	else if (i != j && j != k && k != i)
	  sum += (gcd(i, j, k) * 6);
	else
	  sum += (gcd(i, j, k) * 3);
      }
  cout << sum << '\n';
  return 0;
}
