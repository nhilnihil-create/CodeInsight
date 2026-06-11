#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double L;
  cin >> L;
  L /= 3.0;
  cout << fixed << setprecision(6) << L * L * L << endl;
}
