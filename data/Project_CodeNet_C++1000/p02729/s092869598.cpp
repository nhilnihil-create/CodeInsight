#include <iostream>
#include <cstdlib>

int main()
{
    int N;
    int M;
    
    std::cin >> N;
    
    std::cin >> M;
    
    int result = ((N + M) * (N + M - 1)) / (2 * 1) - (N * M);
    
    std::cout << result;
}