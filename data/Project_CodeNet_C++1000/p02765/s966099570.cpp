#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a,b;
  cin >> a >> b;
  if (a < 10) {
    b = 100 * (10 - a) + b;
  }
  cout << b << endl;
  return 0;
}
