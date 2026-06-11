#include <iostream>
using namespace std;

int main()
{
  int H, A, c = 0;
  cin >> H >> A;

  c = H / A;
  if (H % A != 0)
    c += 1;

  cout << c << endl;
};
