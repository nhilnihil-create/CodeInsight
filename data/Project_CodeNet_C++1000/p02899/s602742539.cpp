#include<iostream>
#include<map>

int main(void){
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    int a;
    for(int i = 0; i < n; i++){
        std::cin >> a;
        mp[a] = i;
    }
    for(auto i = mp.begin(); i != mp.end(); i++){
        if(i != mp.begin()) std::cout << " ";
        std::cout << ++i->second;
    }
    std::cout << std::endl;
    return 0;
}