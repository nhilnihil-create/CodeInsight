#include <iostream>
using namespace std;

int main()
{
  string S, T, U;
  int A, B;
  
  cin >> S >> T;
  cin >> A >> B;
  cin >> U;
  
  if(S==U) cout << A-1 << " " << B << endl;
  else if(T==U) cout << A << " " << B-1 << endl;
}