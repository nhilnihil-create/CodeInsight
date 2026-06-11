#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, c, d; cin >> a >> b >> c >> d;
  a = (a+d-1)/d;
  c = (c+b-1)/b;
  if(a >= c)
    cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}