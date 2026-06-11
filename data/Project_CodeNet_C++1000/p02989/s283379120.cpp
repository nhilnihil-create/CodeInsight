#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

int main()
{

    int n;
    std::cin >> n;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    std::sort(d.begin(), d.end());

    int l, r;
    if (n % 2 == 0)
    {
        r = d[n / 2];
        l = d[n / 2 - 1];
    }

    std::cout << r - l << "\n";
}