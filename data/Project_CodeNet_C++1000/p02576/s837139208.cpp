#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  int N, X, T;
  cin >> N >> X >> T;
  int cycle = (N % X == 0) ? N / X: N / X + 1;
  cout << cycle * T << endl;
  return 0;
}