#include <iostream>

int main() {
    int a;
    int x[101];
    int y[101];

    for (int i = 0; i < 101; i++) {
        x[i] = -1;
        y[i] = -1;
    }

    bool bingo[3][3];
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            std::cin >> a;
            x[a] = i;
            y[a] = j;
            bingo[j][i] = false;
        }
    }

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int b;
        std::cin >> b;

        if (x[b] > -1 && y[b] > -1) {
            bingo[y[b]][x[b]] = true;
        }
    }

    bool yes = false;
    for (int j = 0; j < 3; j++) {
        if (bingo[j][0] && bingo[j][1] && bingo[j][2])
            yes = true;
    }
    for (int i = 0; i < 3; i++) {
        if (bingo[0][i] && bingo[1][i] && bingo[2][i])
            yes = true;
    }
    if (bingo[0][0] && bingo[1][1] && bingo[2][2])
        yes = true;
    if (bingo[2][0] && bingo[1][1] && bingo[0][2])
        yes = true;

    if (yes)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    return 0;
}