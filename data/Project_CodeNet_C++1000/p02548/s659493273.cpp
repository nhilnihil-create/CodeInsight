#include <iostream>
#include <string>
#include <vector>


int main()
{
    int n;
    std::cin >> n;
    int count = 0;
    for (int a = 1; a < n; a++)
    {
        for (int b = 1; b <= (n - 1 )/ a; b++)
        {
            count += 1;
        }
    }
    std::cout << count<< std::endl;
}