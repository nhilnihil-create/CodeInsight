#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for (int i=0; i<n; i++) std::cin>>v[i];
    std::sort(v.begin(),v.end());
    bool p=true;
    for (int i=0; i<v.size()-1; i++)
        if (v[i]==v[i+1]) p=false;
    if (p) std::cout<<"YES";
    else std::cout<<"NO";
    return 0;
}