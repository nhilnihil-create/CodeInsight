#include <iostream>

int main()
{
    int n,k,ans = 0;
    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        int cnt;
        std::cin >> cnt;
        if(cnt >= k) ans ++;
    }
    std::cout << ans;
    return 0;
}