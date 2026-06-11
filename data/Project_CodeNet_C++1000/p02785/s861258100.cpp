#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n,k;
    std::cin>>n>>k;
    std::vector<unsigned long long int> h(n);
    for (int i=0; i<n; i++)
        std::cin>>h[i];
    std::sort(h.begin(),h.end());
    unsigned long long s=0;
    for (int i=0; i<n-k; i++)
        s+=h[i];
    std::cout<<s;
    return 0;
}