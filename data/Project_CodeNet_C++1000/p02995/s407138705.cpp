#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t A, B, C, D, c, d, cd;
  cin >> A >> B >> C >> D;
  c = (B / C) - (A - 1) / C;
  d = (B / D) - (A - 1) / D;
  cd = (B / lcm(C, D)) - (A - 1) / lcm(C, D);
  cout << (B - (A - 1)) - c - d + cd << endl;
}