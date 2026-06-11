#include <iostream>
#include <vector>

int max(std::vector<int> &a)
{
    if (a.size()==0) return 0;
    int m=a[0];
    for (int i=1; i<a.size(); i++)
        if (a[i]>m) m=a[i];
    return m;
}

int main()
{
    int k,n;
    std::cin>>k>>n;
    std::vector<int> a(n);
    for (int i=0; i<n; i++)
        std::cin>>a[i];
    std::vector<int> v;
    for (int i=1; i<n; i++)
        v.push_back(a[i]-a[i-1]);
    v.push_back(k-a[n-1]+a[0]);
    std::cout<<k-max(v);
    return 0;
}
