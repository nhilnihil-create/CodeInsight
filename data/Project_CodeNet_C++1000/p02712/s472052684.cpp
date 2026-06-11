#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
    ll N;
    std::cin >> N;

    ll sum = 0;
    for(ll i=1; i <= N; i++) {
        if(i % 3 == 0) {
            continue;
        }
        else if(i % 5 == 0) {
            continue;
        }
        sum += i;
    }
    std::cout << sum << std::endl;
}