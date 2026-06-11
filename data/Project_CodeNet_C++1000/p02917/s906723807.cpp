#include <iostream>
using namespace std;

int main()
{
  int N, B[10000], res;

  cin >> N;
  for (int i = 0; i < N - 1; i++) cin >> B[i];

  res = B[0];
  for (int i = 0; i < N - 1; i++)
    res += min(B[i], B[i + 1]);
  res += B[N - 2];
  cout << res << endl;
  return 0;
}
