#include <iostream>

unsigned int elevations[100002];
bool reached[100002] = {false};

int main() {
    int n, m, a, b;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> elevations[i + 1];
    }
    int good = n;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        if (elevations[a] > elevations[b]) {
            if (!reached[b]) {
                good -= 1;
                reached[b] = true;
            }
        } else if (elevations[a] == elevations[b]) {
            if (!reached[a]) {
                good -= 1;
                reached[a] = true;
            }
            if (!reached[b]) {
                good -= 1;
                reached[b] = true;
            }
        } else if (!reached[a]){
            good -=1;
            reached[a] = true;
        }
    }
    std::cout << good;
    return 0;
}