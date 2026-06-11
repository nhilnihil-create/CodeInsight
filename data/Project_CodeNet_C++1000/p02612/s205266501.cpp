#include<iostream>

int main()
{
    int N=0;
    int joyo,otsuri=0;

    std::cin >> N;

    joyo=N%1000;

    if(0 != joyo)
    {
        otsuri=1000-joyo;
        std::cout << otsuri;
        return 0;
    }
    std::cout << joyo;

    return 0;
}