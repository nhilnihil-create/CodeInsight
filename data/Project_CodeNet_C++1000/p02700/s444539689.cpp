#include <iostream>

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int taka_count = (c + b - 1) / b;
    int ao_count = (a + d - 1) / d;

    std::cout << (taka_count <= ao_count ? "Yes" : "No") << std::endl;    

    return 0;
}