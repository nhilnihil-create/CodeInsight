#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long S;
  cin >> S;
  long long x;
  long long y;
  x = (1000000000 - S % 1000000000) % 1000000000;
  y = (S + x) / 1000000000;
  cout << 0 << " " << 0 << " "  << 1000000000 <<" "<<1<< " " << x << " " << y << endl;
}