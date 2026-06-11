#include <iostream>
#include <algorithm>
#include <vector>

int main ( ) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> h(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
        if(h[i] >= k) {
            ans++;
        }
    }

    std::cout << ans << "\n";
}