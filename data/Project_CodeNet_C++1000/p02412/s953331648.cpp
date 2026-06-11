#include <iostream>

int main()
{
    while (true) {
        int max, sum_make;
        std::cin >> max >> sum_make;

        if (max == 0 && sum_make == 0) {
            break;
        }

        int cnt = 0;
        for (int small = 1; small <= (sum_make / 3); small++) {
            for (int mid = small + 1; mid <= (sum_make - small) / 2; mid++) {
                for (int big = mid + 1; big <= max; big++) {
                    int sum = small + mid + big;
                    if (sum == sum_make) {
                        cnt++;
                    }
                }
            }
        }
        std::cout << cnt << std::endl;
    }

    return 0;
}