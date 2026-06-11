#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    unsigned long long int s = 1;
    for(std::size_t i = 2; i <= n; ++i){
        s *= i;
    }
    std::cout << s << std::endl;
    return 0;
}