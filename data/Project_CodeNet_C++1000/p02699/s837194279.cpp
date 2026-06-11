#include <iostream>

int main(){
    int s, w;
    std::cin >> s >> w;

    if (s <= w)
    {
        std::cout << "unsafe" << std::endl;
    }
    else
    {
        std::cout << "safe" << std::endl;
    }
    
    return 0;
}