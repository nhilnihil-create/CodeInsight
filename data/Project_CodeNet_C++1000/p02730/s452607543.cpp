#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
  int idxmax = s.size() - 1;
  if(idxmax == 0) return true;
  else if(idxmax == 1 && s[0] != s[1]) return false;
  else if(idxmax == 1 && s[0] == s[1]) return true;
  
  for(int i = 0; i < idxmax / 2; i++)
  {
    if(s[i] != s[idxmax-i])
      return false;
  }
  
  return true;
}

int main()
{
  string s, sleft, sright, res = "Yes";
  cin >> s;
  sleft = s.substr(0, (s.size() - 1) / 2);
  sright = s.substr((s.size() + 1) / 2, (s.size() - 1) / 2);
  
  if(!isPalindrome(s) || !isPalindrome(sleft) || !isPalindrome(sright))
    res = "No";
  
  cout << res << endl;
  return 0;
}