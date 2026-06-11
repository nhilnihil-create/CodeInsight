#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    std::string s;
    std::cin >> s;

    std::string ans = "No";
    if(0 != s.size() % 2){
        std::cout << ans << std::endl;
        return 0;
    }

    bool flg = true;
    int i = 0;
    while(flg && i < s.size()){
        if(0 == i % 2 && 'h' != s.at(i)){
            flg = false;
        }else if(1 == i % 2 && 'i' != s.at(i)){
            flg = false;
        }
        ++i;
    }

    if(flg){
        ans = "Yes";
    }

    std::cout << ans << std::endl;
    return 0;
}