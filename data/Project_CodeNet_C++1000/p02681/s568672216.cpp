#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s,t,u;
  cin >> s >> t;
  u=t.substr(0,s.size());
  if (s==u && t.size()-s.size()==1)
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }
  
}
