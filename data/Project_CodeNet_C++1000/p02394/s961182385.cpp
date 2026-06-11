#include <algorithm>
#include <iostream>

int main(void)
{
    int W, H, x, y, r;

    std::cin >> W;
    std::cin >> H;
    std::cin >> x;
    std::cin >> y;
    std::cin >> r;

    if (x >= r && x <= W-r &&
        y >= r && y <= H-r)
    {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}