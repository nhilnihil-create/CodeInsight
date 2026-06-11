#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int ticket[3][3];
    bool scratched[3][3] = {};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> ticket[i][j];
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        int x;
        std::cin >> x;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scratched[i][j] |= (ticket[i][j] == x);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        bool bingo = true;
        for (int j = 0; j < 3; j++) {
            bingo &= scratched[i][j];
        }
        if (bingo) {
            std::cout << "Yes";
            return 0;
        }
    }

    for (int j = 0; j < 3; j++) {
        bool bingo = true;
        for (int i = 0; i < 3; i++) {
            bingo &= scratched[i][j];
        }
        if (bingo) {
            std::cout << "Yes";
            return 0;
        }
    }

    {
        bool bingo = true;
        for (int i = 0; i < 3; i++) {
            bingo &= scratched[i][i];
        }
        if (bingo) {
            std::cout << "Yes";
            return 0;
        }
    }

    {
        bool bingo = true;
        for (int i = 0; i < 3; i++) {
            bingo &= scratched[i][3 - i - 1];
        }
        if (bingo) {
            std::cout << "Yes";
            return 0;
        }
    }

    std::cout << "No";

    return 0;
}