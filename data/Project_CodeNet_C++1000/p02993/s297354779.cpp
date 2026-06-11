#include<iostream>

int main(void){
    std::string s;
    std::cin >> s;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            std::cout << "Bad" << std::endl;
            return 0;
        }
    }
    std::cout << "Good" << std::endl;
    return 0;
}