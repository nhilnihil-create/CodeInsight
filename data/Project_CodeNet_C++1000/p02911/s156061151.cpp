#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    fast_io();

    int n,k,q; std::cin >> n >> k >> q;
    std::vector<int> sankasha(n,0);
    for(int i=0; i<q; i++){
        int ai; std::cin >> ai;
        sankasha[ai-1]++;
    }

    for(int i=0; i<n; i++){
        if(sankasha[i]>q-k) std::cout << "Yes" << "\n";
        else std::cout << "No" << "\n";
    }
    return 0;
}
