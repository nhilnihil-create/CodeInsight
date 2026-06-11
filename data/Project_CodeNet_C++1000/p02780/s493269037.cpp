#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    int k,n,ind=0;
    std::cin>>n>>k;
    std::vector<int> p(n);
    for (int i=0; i<n; i++) std::cin>>p[i];
    double max_sum=0,sum=0,first;
    first=1.0*p[0]*(p[0]+1)/2/p[0];
    for (int i=0; i<k; i++)
    {
        sum+=1.0*p[i]*(p[i]+1)/2/p[i];
    }
    max_sum=sum;
    for (int i=k; i<n; i++)
    {
        sum-=first;
        first=1.0*p[++ind]*(p[ind]+1)/2/p[ind];
        sum+=1.0*p[i]*(p[i]+1)/2/p[i];
        if (sum>max_sum) max_sum=sum;
    }
    std::cout << std::setprecision(10) << std::fixed << max_sum;
    return 0;
}
