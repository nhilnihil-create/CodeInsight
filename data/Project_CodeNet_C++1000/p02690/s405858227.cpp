#include <iostream>

int main()
{
    unsigned long long x;
    std::cin>>x;
    for (long long int i=-120; i<120; i++)
        for (long long int j=-120; j<120; j++)
        {
            long long a=i*i*i*i*i, b=j*j*j*j*j;
            if (a-b==x)
            {
                std::cout<<i<<" "<<j;
                return 0;
            }
        }
    return 0;
}
