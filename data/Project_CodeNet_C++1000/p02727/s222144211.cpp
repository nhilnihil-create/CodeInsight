#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
  return a > b;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;

  long long int temp;
  long long int p[A], q[B], r[C], pqr[A + B + C];
  for (int i = 0; i < A; i++)
    cin >> p[i];
  for (int i = 0; i < B; i++)
    cin >> q[i];
  for (int i = 0; i < C; i++)
    cin >> r[i];

  sort(p, p + A, compare);
  sort(q, q + B, compare);
  sort(r, r + C, compare);
  
  for (int i = 0; i < X; i++)
    pqr[i] = p[i];
  for (int i = 0; i < Y; i++)
    pqr[X + i] = q[i];
  for (int i = 0; i < C; i++)
    pqr[X + Y + i] = r[i];

  sort(pqr, pqr + X + Y + C, compare);
  long long int sum = 0;
  for (int i = 0; i < X + Y; i++)
    sum += pqr[i];

  cout << sum << '\n';
  return 0;
}
