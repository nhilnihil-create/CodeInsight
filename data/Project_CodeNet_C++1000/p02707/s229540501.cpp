#include <iostream>
#include <vector>

int main(){
    int n = 0;
    int a = 0;

    std::cin >> n;
    std::vector<int> emp(n);

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> a;
        emp[a - 1] += 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout << emp[i] << std::endl;
    }

    return 0;
}