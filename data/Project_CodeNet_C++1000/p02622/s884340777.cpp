#include <iostream>
#include <string>

int main() {
    std::string S, T;
    int ans = 0;

    std::cin >> S >> T;

    for(int i = 0; i < S.size(); i++) {
        if(S.at(i) != T.at(i)) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
