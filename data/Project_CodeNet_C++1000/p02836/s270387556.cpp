#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  string S;
  cin >> S;
  
  int hug = 0;
  
  int ssize = S.size();
  
  for (int i = 0; i < (ssize / 2); i++)
  {
    if(S[i] != S[ssize-1-i])
    {
      hug++;
    }
  }
  
  cout << hug << endl;
}