#include <iostream>
int main()
{
    int n,m;
    std::cin >> n >> m;
    n=(n*(n-1))/2;
    m=(m*(m-1))/2;
    std::cout << n+m << std::endl;

}