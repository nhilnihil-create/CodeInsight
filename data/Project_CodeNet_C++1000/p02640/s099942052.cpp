#include<iostream>

int main()
{
    int X,Y=0;
    std::cin >> X >> Y;
    int clane,turtle=0;

    for(int i=0; i<(X+1); i++)
    {
        clane = (X-i)*2;
        turtle = i*4;
        if((clane+turtle)==Y)
        {
            std::cout << "Yes";
            return 0;
        }
    }
    std::cout << "No";
    return 0;
}