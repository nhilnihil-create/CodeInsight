#include <bits/stdc++.h>
using namespace std;

signed main()
{
  int n;
  string p, s;
  cin >> p >> s;

  p += p;
  n = p.find(s);
  
  if (n < 0){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
  
  return (0);
}