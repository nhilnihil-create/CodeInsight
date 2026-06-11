#include <iostream>
#include <vector>
#include <map>

#define MAX_A 100000
#define MAX_B 100000

int main() {
    int A, B, M;
    std::cin >> A >> B >> M;

    std::vector<int> a(A);
    int min_a = 300000;
    for (int i = 0; i < A; i++) {
        std::cin >> a[i];
        if (a[i] < min_a) {
            min_a = a[i];
        }
    }

    std::vector<int> b(B);
    int min_b = 300000;
    for (int i = 0; i < B; i++) {
        std::cin >> b[i];
        if (b[i] < min_b) {
            min_b = b[i];
        }
    }

    int min = min_a + min_b;

    for (int i = 0; i < M; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;

        int sum = a[x - 1] + b[y - 1] - c;
        if (sum < min) {
            min = sum;
        }
    }

    std::cout << min << std::endl;
    
    return 0;
}