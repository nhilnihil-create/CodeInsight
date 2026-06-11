//#define _XCODE_DEBUG

#include <iostream>
#include <vector>
#include <algorithm>

#ifdef _XCODE_DEBUG
    #include <fstream>
#endif

using ll = long long;

int main() {
    #ifdef _XCODE_DEBUG
        std::ifstream in("input.txt");
        std::cin.rdbuf(in.rdbuf());
    #endif
    
    // input data
    int N;
    std::cin >> N;
    ll X, L;
    std::vector<std::pair<ll, ll>> pair_vec;
    for (int i=0; i<N; ++i) {
        std::cin >> X >> L;
        pair_vec.push_back(std::make_pair(X-L,X+L));
    }
    // sort vector
    std::sort(pair_vec.begin(), pair_vec.end(), [](auto &left, auto &right){
        return left.second < right.second;
    });
    
    int ans = 1;
    ll bp = pair_vec[0].second;
    for (int i=1; i<N; ++i) {
        if (bp <= pair_vec[i].first){
            ++ans;
            bp = pair_vec[i].second;
        }
    }
    std::cout << ans << "\n";
    return 0;
}