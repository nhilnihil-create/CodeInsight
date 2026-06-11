#include<iostream>
#include<map>

int main(void){
    int n;
    std::cin >> n;
    // std::vector<int> a(n), b(n);
    std::multimap<int, int> mp;
    int a, b;
    for(int i = 0; i < n; i++){
        std::cin >> a >> b;
        mp.insert(std::make_pair(b, a));
    }
    int cur = 0;
    for(auto i = mp.begin(); i != mp.end(); i++){
        cur += i->second;
        if(cur > i->first){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}