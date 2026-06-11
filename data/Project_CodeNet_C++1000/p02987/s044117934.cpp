#include <iostream>
#include <vector>

int main()
{
    std::vector<int> n(26, 0);
    for (int i = 0; i < 4; i++)
    {
        char c; std::cin >> c;
        n[c-'A']++;
    }

    bool b = true;
    for (const auto nn: n)
    {
        if (nn != 2 && nn != 0)
        {
            b = false;
        }
    }

    std::cout << (b?"Yes":"No") << std::endl;
    return 0;
}
