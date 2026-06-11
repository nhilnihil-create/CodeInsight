#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    size_t dd = n / 2;
    std::cout << (v[dd] - v[dd-1]) << std::endl;
    return 0;
}
