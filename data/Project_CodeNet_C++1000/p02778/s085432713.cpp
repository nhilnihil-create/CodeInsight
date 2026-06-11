#include<iostream>

int main(void){
    std::string s;
    std::cin >> s;
    for(int i = 0; i < s.size(); i++){
	std::cout << "x";
    }
    std::cout << std::endl;
    return 0;
}

