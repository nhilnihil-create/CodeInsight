#include <iostream>

#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::sort;

static int N;
static int X[100000], L[100000];
static int table[100000];

static int
solve()
{
  for (int n = 0; n < N; n++)
  {
    table[n] = n;
  }
  sort(&table[0], &table[N],
       [](int const &lhs, int const &rhs) {
         return X[lhs] + L[lhs] < X[rhs] + L[rhs];
       });
  int count = 0;
  int right = -1000000001;
  for (int n = 0; n < N; n++)
  {
    int t = table[n];
    if (right <= X[t] - L[t])
    {
      count++;
      right = X[t] + L[t];
    }
  }
  return count;
}

int
main()
{
  cin >> N;
  for (int n = 0; n < N; n++)
  {
    cin >> X[n] >> L[n];
  }
  cout << solve() << endl;
  return 0;
}
