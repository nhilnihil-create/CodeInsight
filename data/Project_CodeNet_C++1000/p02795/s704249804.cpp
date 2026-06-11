#include <bits/stdc++.h>

int main()
{
    int h,w,n;
    std::cin >> h >> w >> n;

    int mx = std::max(h,w);

    int ans = 0;
    for (ans = 0; 0 < n; ans++) {
        n-=mx;
    }

    std::cout << ans << std::endl;

    return 0;
}
