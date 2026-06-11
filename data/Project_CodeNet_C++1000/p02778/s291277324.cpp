#include <iostream>
using namespace std;

int main()
{
  string S;
  cin >> S;
  
  for(unsigned int i = 0; i < S.length(); ++i)
  {
    S.replace(i, 1, "x");
  }
  
  cout << S << endl;
}