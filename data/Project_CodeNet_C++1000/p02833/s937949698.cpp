#include <iostream>
typedef long long ll;

int main()
{
    ll N;
    std::cin >> N;

    if (N % 2 != 0)
    {
        std::cout << 0 << std::endl;
    }
    else
    {
        ll K = N / 2;
        ll cnt = 0;
        while (K != 0)
        {
            cnt += K / 5;
            K /= 5;
        }
        std::cout << cnt << std::endl;
    }

    return 0;
}
