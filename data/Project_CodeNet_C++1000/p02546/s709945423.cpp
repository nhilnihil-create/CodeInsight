#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  
  cin >> s;
  if (*(s.end() - 1) == 's')
    s += "es";
  else
    s += "s";
  cout << s << endl;
  return (0);
}