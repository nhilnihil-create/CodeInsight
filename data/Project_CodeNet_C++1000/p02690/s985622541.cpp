#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    for (int a = -118; a < 120; a++) {
        for (int b = -118; b < 120; b++) {
            if (pow(a,5) - pow(b,5) == x) {
                printf("%d %d\n", a, b);
                goto end;
            }
        }
    }
    end:
    return 0;
}