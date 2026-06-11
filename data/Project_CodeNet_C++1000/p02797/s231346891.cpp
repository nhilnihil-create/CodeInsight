#include <iostream>
#include <cmath>

int main(){
    int n, k, s;
    std::cin >> n >> k >> s;

    if (s < std::pow(10, 9))
    {
        for (int i = 0; i < k; i++)
        {
            std::cout << s << " ";
        }
        for (int i = 0; i < n - k; i++)
        {
            std::cout << s + 1 << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            std::cout << s << " ";
        }
        for (int i = 0; i < n - k; i++)
        {
            std::cout << 1 << " ";
        }
    }
    
    return 0;
}