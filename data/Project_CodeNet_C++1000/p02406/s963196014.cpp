#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x = i;
        if (x % 3 == 0) {
            printf(" %d", i);
            continue;
        }
        while (x) {
            if (x % 10 == 3) {
                printf(" %d", i);
                break;
            }
            x /= 10;
        }
    }
    printf("\n");

    return 0;
}