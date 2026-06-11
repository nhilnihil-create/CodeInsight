#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAX = 1000000000;

int main()
{
  unsigned long long S;
  cin >> S;
  if (S == MAX * MAX)
  {
    cout << 0 << ' ' << 0 << ' ' << MAX << ' ' << 0 << ' ' << 0 << ' ' << MAX << endl;
    return 0;
  }
  unsigned long long p = S / MAX, r = S % MAX;
  cout << 0 << ' ' << 0 << ' ' << MAX << ' ' << 1 << ' ' << MAX - r << ' ' << p + 1 << endl;
}