#include <iostream>
#include <string>
int main()//170a
{
    int inN[5];

    // インプット
    std::cin >> inN[0] >> inN[1] >> inN[2] >> inN[3] >> inN[4];
    for (int i = 0;i < 5; i++)
    {
        if (inN[i] == 0)
        {
            std::cout << (i+1);

        }
    }


}