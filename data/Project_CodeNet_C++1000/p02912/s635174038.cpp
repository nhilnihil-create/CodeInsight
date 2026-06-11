#include<iostream>
#include<set>

int main(void){
    int n, m;
    std::cin >> n >> m;
    std::multiset<int> as;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        as.insert(a);
    }
    // auto max = std::next(as.end(), -1);
    // as.erase(max);
    // max = std::next(as.end(), -1);
    // std::cout << *max << std::endl;
    for(int i = 0; i < m; i++){
        auto max = std::next(as.end(), -1);
        int redu = *max / 2;
        as.erase(max);
        as.insert(redu);
        // as.
        // std::cout << *max << std::endl;
    }
    long long ans = 0;
    for(auto i = as.begin(); i != as.end(); i++){
        ans += *i;
    }
    std::cout << ans << std::endl;
    return 0;
}