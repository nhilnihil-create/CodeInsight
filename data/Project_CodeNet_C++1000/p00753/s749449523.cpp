#include <cstdio>

using namespace std;

int n;

bool T[123456 * 2 + 1];
int C[123456 * 2 + 1];

void sieve() {
    for (int i = 0; i <= 123456 * 2; i++) {
        T[i] = true;
    }
    T[0] = T[1] = false;
    for (int i = 1; i <= 123456 * 2; i++) {
        if (T[i]) {
            for (int j = 2 * i; j <= 123456 * 2; j += i) {
                T[j] = false;
            }
        }
    }

    int c = 0;
    for (int i = 1; i <= 123456 * 2; i++) {
        if (T[i]) { c++; }
        C[i] = c;
    }
}

int solve() {
    return C[n * 2] - C[n];
}

int main() {
    sieve();
    for (;;) {
        scanf("%d", &n);
        if (!n) { break; }
        printf("%d\n", solve());
    }
    return 0;
}