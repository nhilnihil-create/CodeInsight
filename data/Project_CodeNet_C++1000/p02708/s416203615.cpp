#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  unsigned long long int N, K, sum = 0, i;
  cin >> N >> K;
  for (i = K; i <= N + 1; i++){
    sum += ((N + 1 - i) * i + 1);
    sum %= 1000000007;
  }
  cout << sum << '\n';
  return 0;
}
