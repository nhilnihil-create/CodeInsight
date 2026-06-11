#include <iostream>

int main(){
    unsigned long long int x;
    std::cin >> x;

    unsigned long long int n = 100;
    int count = 0;
    while (n < x)
    {
        n += n / 100;
        count++;
    }
    std::cout << count << std::endl;

    return 0;
}