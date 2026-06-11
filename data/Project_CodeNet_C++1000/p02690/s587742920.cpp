#include <bits/stdc++.h>
int main() {
    long X;
    std::cin >> X;
    for (long a = 0; a <= 120; a++)
        for (long b = -120; b < a; b++)
            if ((a * a * a * a * a - b * b * b * b * b) == X) {
                std::cout << a << " " << b << std::endl;
                return 0;
            }
}
