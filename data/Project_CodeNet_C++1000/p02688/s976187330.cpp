#include <iostream>
#include <vector>

int main()
{
    int n,k;
    std::cin>>n>>k;
    std::vector<int> v(n,0);
    for (int i=0; i<k; i++)
    {
        int d;
        std::cin>>d;
        for (int j=0; j<d; j++)
        {
            int x;
            std::cin>>x;
            v[x-1]++;
        }
    }
    int cnt=0;
    for (int i=0; i<n; i++) if (!v[i]) cnt++;
    std::cout<<cnt;
    return 0;
}