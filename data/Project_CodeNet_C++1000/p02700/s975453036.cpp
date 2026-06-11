#include <bits/stdc++.h>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    const int X = (A + D - 1) / D;
    const int Y = (C + B - 1) / B;

    if (X >= Y) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
