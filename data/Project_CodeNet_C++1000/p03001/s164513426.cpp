#include <iostream>

int main()
{
  int W, H, X, Y;
  std::cin >> W >> H >> X >> Y;

  // flip/mirror to make x<=W/2, y<=H/2, y/x<=H/W
  double w = double(W);
  double h = double(H);
  double x = double(X);
  double y = double(Y);

  int has_multi_cut = 2 * X == W && 2 * Y == H ? 1 : 0;
  std::cout << std::fixed << w * h / 2 << " " << has_multi_cut << std::endl;

  return 0;
}
