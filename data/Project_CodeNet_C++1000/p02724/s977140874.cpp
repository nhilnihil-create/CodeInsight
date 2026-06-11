#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long

int main()
{
    ll X;
    std::cin >> X;

    ll happy = 1000 * (X / 500);
    ll now_money = X % 500;

    happy += 5 * (now_money / 5);

    std::cout << happy << std::endl;
}