#include <iostream>

int main(){
    int h, a;
    std::cin >> h >> a;

    int count = 0;
    while (0 < h)
    {
        h -= a;
        count++;
    }
    
    std::cout << count << std::endl;

    return 0;
}