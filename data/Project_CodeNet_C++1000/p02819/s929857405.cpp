#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000000];

int main()
{
  int64_t X;
  cin >> X;
  for (int i = 2; i < 1000000; i++)
  {
    isPrime[i] = true;
  }
  for (int i = 2; i < 1000000; i++)
  {
    if (!isPrime[i])
      continue;
    for (int j = 2; i * j < 1000000; j++)
    {
      isPrime[i * j] = false;
    }
  }
  for (int i = X; i < 1000000; i++)
  {
    if (isPrime[i])
    {
      cout << i << endl;
      break;
    }
  }
}
