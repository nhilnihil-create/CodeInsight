#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  long double A, B, ans;
  long long trueAns;
  cin >> A;
  cin >> B;
  B = round(B * 100);
  ans = A * B;
  ans /= 100;
  trueAns = ans;
  cout << trueAns << endl;
  return 0;
}
