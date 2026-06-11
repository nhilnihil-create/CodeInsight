#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main(){
    unsigned long long int n, a, b;
    std::cin >> n >> a >> b;

    unsigned long long int ans_1 = (n / (a + b)) * a;
    unsigned long long int ans_2 = std::min(a, n % (a + b));

    std::cout << ans_1 + ans_2 << std::endl;

    return 0;
}