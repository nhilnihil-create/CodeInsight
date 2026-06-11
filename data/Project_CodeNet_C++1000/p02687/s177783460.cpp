#include<iostream>
#include<string>
int main()
{
    std::string s;
    std::cin >> s;

    if (s=="ABC"){
        std::cout << "ARC" << std::endl;
    }
    
    if (s=="ARC"){
        std::cout << "ABC" << std::endl;
    }
    
}