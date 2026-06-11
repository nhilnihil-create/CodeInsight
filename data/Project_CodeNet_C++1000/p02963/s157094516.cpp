#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1000000000;

int main()
{
  int64_t S, x1 = 0, y1 = 0, x2 = MAX, y2 = 1, x3, y3;
  cin >> S;
  if (S == MAX * MAX)
  {
    y2 = 0;
    x3 = y3 = MAX;
  }
  else
  {
    int64_t p = S / MAX, r = S % MAX;
    x3 = MAX - r, y3 = p + 1;
  }
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
}