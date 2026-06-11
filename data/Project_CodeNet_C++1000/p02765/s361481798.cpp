#include <iostream>

int main(void)
{
        int N, R;
        std::cin >> N >> R;

        if(N >= 10)
        {
                std::cout << R << std::endl;
        }
        else
        {
                /*
                 * ans - 100+(10-N) = R
                 * <-> ans = -(100 + (10-N) + R
                 * */
                std::cout << (R + (100 * (10-N))) << std::endl;
        }

        return 0;

}
