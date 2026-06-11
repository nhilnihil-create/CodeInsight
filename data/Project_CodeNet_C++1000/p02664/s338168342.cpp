#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;
  int a = s.find("?");
  while(a != -1)
  {
    s.replace(a, 1, "D");
    a = s.find("?");
  }
  cout << s << endl;
}