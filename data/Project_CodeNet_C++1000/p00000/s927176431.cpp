#include <iostream>

static const int MaxNum = 9;
static void print_qq()
{
    for (int i = 1; i <= MaxNum; ++i) {
        for (int j = 1; j <= MaxNum; ++j) {
            std::cout << i << "x" << j << "=" << i * j << std::endl;
        }
    }
}

int main()
{
    print_qq();
}