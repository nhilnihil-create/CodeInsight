#include <iostream>
using namespace std;

int main()
{
  string s;
  bool odd_step=true, even_step=true;
  cin >> s;
  for(int i=0; i<s.size(); i+=2)
  {
    if(s[i]=='L')
    {
      even_step = false;
      break;
    }
  }
  for(int i=1; i<s.size(); i+=2)
  {
    if(s[i]=='R')
    {
      odd_step = false;
      break;
    }
  }
  
  cout << (odd_step && even_step ? "Yes" : "No") << endl;
  return 0;
}