#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<double> p(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }
    std::vector<double> s(n + 1);
    
    for (int i = 0; i < n; i++)
    {
        double tmp = p[i];
        p[i] = 0;
        for (int j = 1; j <= tmp; j++)
        {
            p[i] += j / tmp;
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        s[i + 1] = s[i] + p[i];
    }

    double sum_max = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        double sum = s[i + k] - s[i];
        if (sum_max < sum)
        {
            sum_max = sum;
        }
    }

    std::cout << std::fixed << std::setprecision(12) << sum_max << std::endl;

    return 0;
}