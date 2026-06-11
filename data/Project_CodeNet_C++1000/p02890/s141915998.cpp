#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(0);
    int64_t n;
    std::cin >> n;
    std::vector<int> B(n+1, 0);
    for (int i=0;i<n;++i)
    {
        int a;
        std::cin >> a;
        B[a]++;
    }
    std::sort(B.begin(), B.end(), std::greater<int>());
    while (B.back() == 0) B.pop_back();

    int div = n;
    int j = 0;
    int sum = n;
    for (int i=1;i<=n;++i)
    {
        while (j < B.size() && B[j] >= div) { sum -= B[j]; ++j; }
        int k = (div == 0 ? i : (j + sum / div));
        if (k >= i || div == 0) std::cout << div << "\n";
        else { --div; --i; }
    }

    return 0;
}