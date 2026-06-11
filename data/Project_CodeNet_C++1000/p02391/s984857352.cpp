#include <iostream>

int main(){
    int a,b;
    std::cin >> a >> b;
    std::cout << "a ";
    if(a==b){
        std::cout << "==";
    }
    else if(a<b){
        std::cout << "<";
    }
    else{
        std::cout << ">";
    }
    std::cout << " b" << std::endl;
    return 0;
}
