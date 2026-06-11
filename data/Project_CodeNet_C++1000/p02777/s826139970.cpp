#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a, b; cin >> a >> b;
  int na, nb; cin >> na >> nb;
  string s; cin >> s;
  if(a == s) --na;
  else --nb;
  
  cout << na << " " << nb;
  return 0;
}