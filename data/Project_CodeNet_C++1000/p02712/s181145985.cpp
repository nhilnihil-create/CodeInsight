#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int N, i;
  long long int sum = 0;
  cin >> N;
  for (i = 1; i <= N; i++)
    if (i % 3 != 0 && i % 5 != 0)
      sum += i;
  cout << sum << '\n';
  return 0;
}
