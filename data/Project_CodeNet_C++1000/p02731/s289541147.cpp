#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  double n;
  cin >> n;
  n /= 3.0;
  cout << fixed << setprecision(20) << n * n * n << endl;

  return 0;
}