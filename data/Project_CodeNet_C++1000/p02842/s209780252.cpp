#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main()
{
  int N;
  cin >> N;

  int X = (floor)(N / 1.08);
  for (int i = 0; floor((X+i) * 1.08) <= N; i++)
  {
    if (floor((X+i) * 1.08) == N) {
      cout << X + i;
      return 0;
    }
  }
  cout << ":(";
}