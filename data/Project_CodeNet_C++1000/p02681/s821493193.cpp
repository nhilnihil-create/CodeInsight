#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  int count = 0;
  string S;
  string T;
  cin >> S;
  cin >> T;
  for (int i = 0; i < S.length();i++)
  {
    if(S[i] != T[i])
    {
      count++;
    }
  }
  if(count == 0)
  {cout << "Yes" << endl;}
  else
  {cout << "No" << endl;}
}
