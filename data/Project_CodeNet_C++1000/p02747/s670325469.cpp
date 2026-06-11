#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s; cin >> s;
  for(int i = 0; i < s.size(); i++)
  {
    if(i & 1 && s[i] != 'i')
    {
      cout << "No";
      return 0;
    }
    if(!(i & 1) && s[i] != 'h')
    {
      cout << "No";
      return 0;
    }
  }
  if(s[s.size() - 1] == 'h') cout << "No";
  else cout << "Yes";
  
  return 0;
}