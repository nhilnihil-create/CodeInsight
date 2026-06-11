#include <iostream>
using namespace std;

int main()
{
  string s, res = "No";
  cin >> s;
  for(int i = 1; i < s.size(); i++)
  {
    if(s[0] == s[i])
    {
      switch(i)
      {
        case 1:
          if(s[2] == s[3] && s[0] != s[2]) res = "Yes";
          break;
        case 2:
          if(s[1] == s[3] && s[0] != s[3]) res = "Yes";
          break;
        case 3:
          if(s[1] == s[2] && s[0] != s[1]) res = "Yes";
          break;
      }
      break;
    }
  }
  cout << res << endl;
  return 0;
}