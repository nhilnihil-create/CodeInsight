#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int k, x;

  cin >> k >> x;

  int begin = x - k + 1;

  int end = x + k - 1;

  for (int i = begin; i <= end; i++)
  {
    cout << i << " ";
  }
}
