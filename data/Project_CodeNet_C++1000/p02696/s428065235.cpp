#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int A, B, N, i, j, ans = 0;
  cin >> A >> B >> N;
  ans = (N >= B - 1)? A * (B - 1) / B - A * ((B - 1) / B) :
    (A * N / B - A * (N / B));
  cout << ans << '\n';
  return 0;
}
