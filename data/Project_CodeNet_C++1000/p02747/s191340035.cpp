#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  string s;
  cin >> s;
  bool ans = true;
  if (s.size() % 2 == 1)
  {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < s.size(); i++)
  {
    if(i % 2 == 0) ans = s.at(i) == 'h';
    if(i % 2 == 1) ans = s.at(i) == 'i';
    if(!ans)
    {
      cout << "No" << endl;
      return 0;
    } 
  }
  cout << "Yes" << endl;
  return 0;
}