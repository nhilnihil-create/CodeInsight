#include <iostream>

int main() {
    int X, Y;
    bool ans = true;

    std::cin >> X >> Y;

    for(int i = 0; i <= X && ans; i++) {
        int tatle = 2 * i, bard = 4 * (X - i);

        if(tatle + bard == Y) {
            ans = false;
        }
    }

    if(ans) {
        std::cout << "No" << std::endl;
    }
    else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}
