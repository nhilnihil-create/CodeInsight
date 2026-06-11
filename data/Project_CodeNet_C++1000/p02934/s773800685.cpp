#include <iostream>
#include <vector>
#include<iomanip>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        ans += 1 / (1.0 * a[i]);
    }

    std::cout << std::fixed << std::setprecision(15) << 1 / ans << "\n";
}