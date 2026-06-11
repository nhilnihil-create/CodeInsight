#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;

  cin >> a >> b;

  string a_s = string(b, '0' + a);
  string b_s = string(a, '0' + b);

  if (a_s <= b_s)
  {
    cout << a_s << endl;
  }
  else
  {
    cout << b_s << endl;
  }
}
