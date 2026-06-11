#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI (acos(-1));


int main()
{
  string S;
  cin >> S;

  string T;
  cin >> T;

  int A,B;
  cin >> A >> B;

  string U;
  cin >> U;

  if(U == S)
  {
    A--;
  }else
  {
    B--;
  }
  
  cout << A << " " << B;



}
