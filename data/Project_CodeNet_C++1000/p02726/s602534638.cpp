#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, X, Y;
  cin >> N >> X >> Y;
  int distance[N] = {0};
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
      distance[min(abs(j - i), abs(X - i) + 1 + abs(Y - j))]++;
  for (int i = 1; i < N; i++)
    cout << distance[i] << '\n';
  return 0;
}
