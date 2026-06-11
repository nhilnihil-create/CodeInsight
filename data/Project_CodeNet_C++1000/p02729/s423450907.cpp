#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    int N, M;
    std::cin >> N >> M;

    int sum1 = N * (N-1) / 2;
    int sum2 = M * (M-1) / 2;

    int sum = sum1 + sum2;

    std::cout << sum << std::endl;
}