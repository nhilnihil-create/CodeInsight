#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << fixed << setprecision(6) << ((n + 1) / 2) / (float) n << endl;
  return 0;
}