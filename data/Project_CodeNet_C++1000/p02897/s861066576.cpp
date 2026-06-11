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
  int x = n;
  if (x % 2 == 0) {
    cout <<  0.5 << endl;
  }
  else {
    cout << 1 / n * (x / 2 + 1) << endl;
  }
  return 0;
}