#include <iostream>
#include <string>

int main()
{
    std::string str,str2,str3;
    std::cin >> str;
    str2="ABC";
    str3="ARC";

    if(str==str2 ){
     std::cout << str3 << std::endl;
    }
    else{
        std::cout << str2 << std::endl;
    }
}