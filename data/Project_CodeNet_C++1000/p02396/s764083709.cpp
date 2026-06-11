#include <iostream>

int main(){
    int a;
    int i = 1;

    while((std::cin >> a) != NULL && i <= 10000){
        std::cout << "Case " << i << ": " << a << "\n";
        i++;
    }   
    
    return 0;
}