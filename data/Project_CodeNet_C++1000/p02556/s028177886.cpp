#include <iostream>

int main() {
    int n, x, y;

    std::cin >> n;
    std::cin >> x >> y;

    int z, z_max, z_min, w, w_max, w_min;
    z_max = z_min = x + y;
    w_max = w_min = x - y;

    for (int i = 1; i < n; i++) {
        std::cin >> x >> y;

        z = x + y;
        w = x - y;

        if (z > z_max) {
            z_max = z;
        } else if (z < z_min) {
            z_min = z;
        }
        if (w > w_max) {
            w_max = w;
        } else if (w < w_min) {
            w_min = w;
        }
    }

    z_max -= z_min;
    w_max -= w_min;

    if (z_max > w_max) {
        std::cout << z_max << std::endl;
    } else {
        std::cout << w_max << std::endl;
    }
    
}