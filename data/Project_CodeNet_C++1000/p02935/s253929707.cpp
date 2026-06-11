#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(void){
    int N;
    double ans = 0;
    std::cin >> N;
    std::vector<int> v(N);
    for (int i=0; i<N; ++i){
        std::cin >> v.at(i);
    }

    std::sort(v.begin(), v.end());

    ans += v.at(0) / pow(2, N - 1);
    for (int i=1; i<N; ++i) {
        ans += v.at(i) / pow(2, N - i);
    }
    std::cout << ans << std::endl;

    return 0;
}
