#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> dpt(N+1, std::vector<int>(N+1, 0));
    int result = 0;
    for (int i = 1; i < N + 1; i++) {
        for (int j = i+1; j < N + 1; j++) {
            if (s[j-1] == s[i-1]) {
                if (j - dpt[i-1][j-1] > i) {
                    dpt[i][j] = dpt[i-1][j-1] + 1;
                }
            }
            if (dpt[i][j] > result) result = dpt[i][j];
        }
    }
    std::cout << result << std::endl;
}