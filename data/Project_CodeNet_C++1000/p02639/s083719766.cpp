#include<iostream>

int main()
{
    int x[5]={0};
    for(int i=0; i<5; i++)
    {
        std::cin >> x[i];
        if(x[i] == 0)
        {
            std::cout << i+1;
            return 0;
        }
    }
    return 0;
}