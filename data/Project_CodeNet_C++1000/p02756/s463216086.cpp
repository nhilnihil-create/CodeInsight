#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    std::string S;
    int Q;
    int reverse = 0;

    std::cin >> S >> Q;

    for (int i=0; i<Q; i++)
    {
        char order;
        std::cin >> order;

        if (order == '1')
        {
            reverse = 1 - reverse;
        }
        else
        {
            std::cin >> order;
            if ((order == '1' && reverse == 0) || (order == '2' && reverse == 1))
            {
                std::cin >> order;
                S = order + S;
            }
            else
            {
                std::cin >> order;
                S += order;
            }
        }
        //std::cout << S << std::endl;
    }

    if (reverse == 1) std::reverse(S.begin(), S.end());
    std::cout << S << std::endl;
}