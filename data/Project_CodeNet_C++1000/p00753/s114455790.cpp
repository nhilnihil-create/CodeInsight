#include <iostream>
using namespace std;

const int SIZE = 300000;

bool table[SIZE];

int main() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = true;
    }
    table[0] = table[1] = false;

    for (int n = 2; n * n < SIZE; n++) {
        if (!table[n]) continue;
        for (int i = 2; i * n < SIZE; i++) {
            table[n * i] = false;
        }
    }
    int n;
    while (cin >> n, n) {
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (table[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}