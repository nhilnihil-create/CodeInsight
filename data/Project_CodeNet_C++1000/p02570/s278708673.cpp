#include <iostream>

int main(){
    int D, T, S;
    
    std::cin >> D >> T >> S;

    if(T * S >= D) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;


    return 0;
}