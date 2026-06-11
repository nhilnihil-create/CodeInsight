#include <iostream>

int main(){
    int n = 0;
    int m = 0;
    int a = 0;
    int sum = 0;

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a;
        sum += a;
    }
    
    if (n >= sum)
    {
        std::cout << n - sum << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}