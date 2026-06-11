#include<iostream>

int main()
{
    int X,Y=0;
    std::cin >> X >> Y;
    int clane,turtle=0;

    clane = X*2;
    turtle = X*4;

    if((Y%2)!=0)
    {
        std::cout << "No";
        return 0;
    }   
    if(clane<=Y && Y<=turtle)
    {
        std::cout << "Yes";
        return 0;
    }
    std::cout << "No";
    return 0;
}