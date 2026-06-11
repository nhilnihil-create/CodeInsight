#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long double denominator = 0;
  int i;
  while(cin >> i)
    denominator += (long double)1 / i;
  cout << fixed << setprecision(10) << 1 / denominator << endl;
  return 0;
}