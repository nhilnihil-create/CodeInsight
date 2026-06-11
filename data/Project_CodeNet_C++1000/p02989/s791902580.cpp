#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N, ans=0;
    std::cin >> N;
    std::vector<int> d(N);
    for (int i=0; i<N; ++i){
        std::cin >> d.at(i);
    }
    std::sort(d.begin(), d.end());

    if (d.at(N / 2) != d.at(N / 2 - 1)) {
        ans = d.at(N / 2) - d.at(N / 2 - 1);
    }

    std::cout << ans << std::endl;

    return 0;
}
