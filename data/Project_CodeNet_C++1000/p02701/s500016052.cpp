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

    std::vector<std::string> S(N);
    for(ll i=0; i < N; i++) {
        std::cin >> S[i];
    }

    std::sort(S.begin(), S.end());

    ll sum = 1;
    std::string tmp = S[0];

    for(ll i=1; i < N; i++) {
        if(tmp != S[i]) {
            sum++;
            tmp = S[i];
        }
    }

    std::cout << sum << std::endl;
}