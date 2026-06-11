#include <iostream>
#include <vector>

int main()
{
    int n,m;
    std::cin>>n>>m;
    std::vector<unsigned long long int> h(n);
    for (int i=0; i<n; i++) std::cin>>h[i];
    std::vector<bool> good(n,true);
    for (int i=0; i<m; i++)
    {
        int a,b;
        std::cin>>a>>b;
        if (h[b-1]>=h[a-1]) good[a-1]=false;
        if (h[a-1]>=h[b-1]) good[b-1]=false;
    }
    int cnt=0;
    for (int i=0; i<n; i++)
        if (good[i]) cnt++;
    std::cout<<cnt;
    return 0;
}