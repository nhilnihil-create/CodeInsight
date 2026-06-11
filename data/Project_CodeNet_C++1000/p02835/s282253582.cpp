#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int A,B,C;
  cin >> A >> B >> C;
  
  if (A+B+C > 21)
  {
    cout << "bust" << endl;
  }
  else
  {
    cout << "win" << endl;
  }
  
  return 0;
}