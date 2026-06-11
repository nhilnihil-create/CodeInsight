#include <iostream>

static void printQq();
static const int Start = 1;
static const int End = 9;

int main(int /* argc */, char **/* argv */)
{
    printQq();

    return 0;
}

static void printQq()
{
    for (int i = Start; i <= End; ++i) {
       for (int j = Start; j <= End; ++j ) {
           std::cout << i << "x" << j << "=" << i * j << std::endl;
       }
    }
}