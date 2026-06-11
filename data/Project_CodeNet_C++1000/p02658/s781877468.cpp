#include <iostream>
#include <vector>

int main(){
    int n = 0;
    std::cin >> n;
    std::vector<unsigned long long int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] == 0)
        {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    
    unsigned long long int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 1000000000000000000LL / prod)
        {
            prod *= a[i];
        }
        else
        {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << prod << std::endl;

    return 0;
}