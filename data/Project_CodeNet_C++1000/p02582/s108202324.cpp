#include <iostream>

int main(){
    char S[3]; int count{};
    for (auto& r : S) {
        std::cin >> r;
        if (r == 'R') ++count;
    }

    if (S[0] == 'R' && S[1] == 'S' && S[2] == 'R') std::cout << 1 << std::endl;
    else std::cout << count << std::endl;
}