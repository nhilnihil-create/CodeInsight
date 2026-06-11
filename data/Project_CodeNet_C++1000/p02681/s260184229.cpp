#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  
  bool imp = false;
  
  for(int i = 0; i < S.size(); i++)
  {
    if(S.at(i) != T.at(i))
    {
      imp = true;
      break;
    }
  }
  
  if(imp) cout << "No" << endl;
  else cout << "Yes" << endl;
}