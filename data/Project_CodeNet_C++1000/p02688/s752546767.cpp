#include <iostream>

bool hasSnook[102] = {false};

int main() {
    int n, k, di, tmp;
    std::cin >> n >> k;

    int problematic = n;

    for (int i = 0; i < k; ++i) {
        std::cin >> di;
        for (int j = 0; j < di; ++j) {
            std::cin >> tmp;
            if (hasSnook[tmp] == false) {
                problematic -= 1;
                hasSnook[tmp] = true;
            }
        }
    }
    std::cout << problematic;
    return 0;
}