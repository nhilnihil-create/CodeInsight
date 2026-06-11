#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int W, H, x, y;
  cin >> W >> H >> x >> y;

  int num;
  if (W % 2 == 0 && H % 2 == 0 && W / 2 == x && H / 2 == y)
    num = 1;
  else
    num = 0;

  cout << std::fixed << std::setprecision(10) << (double)W * H / 2 << " " << num << endl;

  return 0;
}
