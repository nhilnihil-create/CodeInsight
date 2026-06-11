#include <iostream>
#include <vector>
#include <numeric>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int sum = std::accumulate(a.begin(), a.end(), 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum <= 4 * m * a[i])
        {
            count++;
        }
    }
    if (m <= count)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}