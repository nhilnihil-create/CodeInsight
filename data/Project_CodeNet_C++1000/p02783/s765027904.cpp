#include <iostream>

int h;
int a;
int main() {
    std::cin >> h >> a;
    int times;
    times = h / a;
    if (h % a != 0) {
        times += 1;
    }
    std::cout << times << std::endl;
}