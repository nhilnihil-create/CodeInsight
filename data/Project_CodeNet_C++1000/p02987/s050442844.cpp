#include<iostream>
#include<map>

int main(void){
    std::map<char, int> mp;
    std::string s;
    std::cin >> s;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    for(auto i = mp.begin(); i != mp.end(); i++){
        if(i->second != 2){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}