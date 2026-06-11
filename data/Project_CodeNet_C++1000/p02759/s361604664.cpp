#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define ll long long

int main()
{
    int N;
    std::cin >> N;

    int count = N / 2;
    if(N % 2 != 0) count++;

    std::cout << count << std::endl;

    return 0;
}