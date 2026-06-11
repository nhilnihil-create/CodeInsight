#include <iostream>
using namespace std;

int main()
{
  string S;
  cin >> S;

  bool flg = true;
  for (int i = 0; i < S.size(); i++)
  {
    if (i % 2 == 0 && S[i] == 'L')
    {
      flg = false;
      break;
    }
    if (i % 2 != 0 && S[i] == 'R')
    {
      flg = false;
      break;
    }
  }
  cout << (flg ? "Yes" : "No") << endl;
  return 0;
}
