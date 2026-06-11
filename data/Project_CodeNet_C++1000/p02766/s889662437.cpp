#include<iostream>

int main () {
    int n, k;
    std::cin >> n >> k;

    int ans = 0;
    while(n > 0) {
        n /= k;
        ans++;
    }

    std::cout << ans << "\n";
}