#include <iostream>
#include <map>
#include <algorithm>

int main(void){
    int N, max_p=0;
    std::map<std::string, int> mp;
    std::cin >> N;

    for (int i=0; i<N; ++i){
        std::string s;
        std::cin >> s;
        if (mp.find(s) == mp.end()){
            mp[s] = 0;
        } else {
            ++mp[s];
            max_p = std::max(max_p, mp[s]);
        }
    }

    for (auto& x: mp){
        if (x.second == max_p){
            std::cout << x.first << std::endl;
        }
    }

    return 0;
}
