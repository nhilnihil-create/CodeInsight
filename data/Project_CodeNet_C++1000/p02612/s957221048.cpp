#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int a = n % 1000;
  if (a == 0) cout << a << '\n';
  else cout << 1000 - a << '\n';
  return 0;
}