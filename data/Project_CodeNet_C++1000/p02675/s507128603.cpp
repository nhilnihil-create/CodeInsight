#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s; cin >> s;
  char ch = s[s.length()-1];
  switch(ch)
  {
    case '0':
    case '1':
    case '6':
    case '8':
      cout << "pon";
      break;
    case '3':
      cout << "bon";
      break;
    default:
      cout << "hon";
      break;
  }
  return 0;
}