#include <iostream>
#include <string>

int main() {
    std::string S, T;
    int ans = 10000, tmp;

    std::cin >> S >> T;

    for(int i = 0; i <= S.size() - T.size(); i++) {
        tmp = 0;
        for(int j = 0; j < T.size(); j++) {
            if(S.at(j + i) != T.at(j)) {
                tmp++;
            }
        }

        if(ans > tmp) {
            ans = tmp;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
