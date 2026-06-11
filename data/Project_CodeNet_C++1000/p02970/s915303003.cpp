#include<iostream>
#include<string>
#include<algorithm>

int main () {
    int n, d;
    std::cin >> n >> d;

    int ans = n / (2 * d + 1);
    double ansd = 1.0*n / (2 * d + 1);

    if(ans != ansd) {
        ans++;
    }

    std::cout << ans << std::endl;
}