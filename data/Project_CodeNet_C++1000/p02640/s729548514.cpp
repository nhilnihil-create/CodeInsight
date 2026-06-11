
#include <iostream>
#include <string>


int main()//170b
{
    int inX,inY;

    std::string ansYes("Yes"), retAns("No");

    // インプット
    std::cin >> inX >> inY;
    for (int i = 0;i <= inX; i++)
    {
        if (i * 2 + (inX - i) * 4 == inY)
        {
            retAns = ansYes;
        }


    }
    std::cout << retAns;

    return 0;
}
