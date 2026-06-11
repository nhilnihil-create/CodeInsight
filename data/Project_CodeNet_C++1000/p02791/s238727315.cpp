#include <iostream>
#include <vector>

int main()
{
    long long int n;
    std::cin>>n;
    std::vector<long long int> p(n);
    for (int i=0; i<n; i++) std::cin>>p[i];
    long long min=p[0],count=1;
    for (int i=1; i<n; i++)
    {
        if (p[i]<min)
        {
            count++;
            min=p[i];
        }
    }
    std::cout<<count;
    return 0;
}
