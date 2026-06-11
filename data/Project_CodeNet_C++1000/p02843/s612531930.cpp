#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    std::string s; std::cin >> s;
    int N = s.size();
    if (N < 3) {
        std::cout << 0 << std::endl;
        return 0;
    }
    int i_f = s.size() - 2;
    int over_hundred = 0;
    for (int i = 0; i < i_f; ++i)
        over_hundred += (s[N - 3 - i] - '0') * std::pow(10, i);
    int under_hundred = 0;
    if (((s[N - 1] - '0') + ((s[N - 2] - '0') * 10)) % 5 == 0)
       under_hundred = ((s[N - 1] - '0') + ((s[N - 2] - '0') * 10)) / 5;
    else
       under_hundred = (((s[N - 1] - '0') + ((s[N - 2] - '0') * 10)) / 5) + 1;
    if (under_hundred > over_hundred)
        std::cout << 0 << std::endl;
    else
        std::cout << 1 << std::endl;

    return 0;
}