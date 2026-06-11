#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  int ans = 0;
  for (int i = 0; i < N - 1; i++)
  {
    if (S[i] == S[i + 1])
      ans++;
  }
  ans += 2 * K;
  ans = min(ans, N - 1);
  cout << ans;
  return 0;
}