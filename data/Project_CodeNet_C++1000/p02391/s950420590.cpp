#include <iostream>

int main(void){
    int inputIntA = 0;
    int inputIntB = 0;
    
    /* input */
    std::cin >> inputIntA >> inputIntB;
    
    /* output */
    if(inputIntA < inputIntB)
    {
        std::cout << "a < b" << std::endl;
    }
    else if(inputIntA > inputIntB)
    {
        std::cout << "a > b" << std::endl;
    }
    else
    {
        /* a = b case */
        std::cout << "a == b" << std::endl;
    }
    
    return 0;
}