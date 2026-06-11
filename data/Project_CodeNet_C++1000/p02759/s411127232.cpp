#include <bits/stdc++.h>
#define rep (i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int N;
  cin >> N;

  if (N % 2 == 0)
    cout << N / 2 << endl;
  else
    cout << N / 2 + 1 << endl;

  return 0;
}