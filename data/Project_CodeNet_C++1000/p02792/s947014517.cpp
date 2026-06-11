#include <iostream>
#include <map>
#include <cmath>
#include <utility>

int brCif(int x)
{
    int br=0;
    while (x)
    {
        x/=10;
        br++;
    }
    return br;
}

std::map<std::pair<int,int>,int> mapa;

int main()
{
    int n;
    std::cin>>n;
    int sum1=0,sum2=0;
    for (int i=1; i<=n; i++)
    {
        int prva=i/pow(10,brCif(i)-1),zadnja=i%10;
        if (prva==zadnja)
            sum1++;;
        sum2+=mapa[std::make_pair(zadnja,prva)];
        mapa[std::make_pair(prva,zadnja)]++;
    }
    std::cout<<sum1+sum2*2;
    return 0;
}