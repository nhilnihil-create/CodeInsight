#include <iostream>
#include <algorithm>
#include <iomanip>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b;
    std::cin >> a >> b;
    std::cout << a/b << " " << a%b << " " << std::fixed << std::setprecision(6) << 1.0*a/b << "\n";
    return 0;
}