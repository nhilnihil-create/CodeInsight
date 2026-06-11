#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long

int main()
{
    int N;
    std::cin >> N;

    // 試すのはAとBだけでよい
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += (N-1) / i;
    }
    std::cout << ans << std::endl;
}