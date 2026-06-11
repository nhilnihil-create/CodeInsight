#include <iostream>
#include <string>


int main()
{
    char instr;

    // インプット
    std::cin >> instr;
    if (isupper(instr))
    {
        std::cout << "A";
    }
    else {
        std::cout << "a";

    }

}