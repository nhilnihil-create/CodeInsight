#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t a;
  long double b;
  cin >> a >> b;
  
  int64_t b100 = (int64_t)(b * 100 + 0.001);
  
  cout << (int64_t)(a * b100) / 100 << endl;
}