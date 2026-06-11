#include <iostream>
using namespace std;

int main(void){
    int a;
    int b;
    
    std::cin >> a >> b;
    
    if(a < b) {
        std::cout << "a < b" << std::endl;
    } else if(a > b) {
        std::cout << "a > b" << std::endl;
    } else if(a == b) {
        std::cout << "a == b" << std::endl;
    }
    
}