#include <iostream>
#include <vector>

int main()
{
    int64_t A, B, N;
    std::cin >> A >> B >> N;

    auto maxX = std::min(B-1, N);
    std::cout << (A * maxX / B) - A * (maxX / B) << std::endl;
}
