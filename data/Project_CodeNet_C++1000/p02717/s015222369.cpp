#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

#define ll long long

void change(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    change(X, Y);
    change(X, Z);

    std::cout << X << " " << Y << " " << Z << std::endl;
}