#include <iostream>

int main(){
    int power = 3;
    int x     = 0;
    std::cin >> x;

    int answer = 1;
    for( int i = 0; i < power; ++i ){
        answer = answer * x;
    }
    std::cout << answer << std::endl;
}