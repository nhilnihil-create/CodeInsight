#include <iostream>
int main()
{
    int N,M;
    
    std::cin >> N;
    std::cin >> M;
    int count = (N * (N-1))/2;
    count += (M * (M - 1))/2;
    std::cout << count;
}
