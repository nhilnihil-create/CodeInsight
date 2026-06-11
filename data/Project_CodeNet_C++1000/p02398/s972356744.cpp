#include <iostream>

int main()
{
    int first, last, divided;
    std::cin >> first >> last >> divided;

    int divisor;
    int cnt = 0;
    for (divisor = first; divisor <= last; divisor++){
        if (divided % divisor == 0){
            cnt++;
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}