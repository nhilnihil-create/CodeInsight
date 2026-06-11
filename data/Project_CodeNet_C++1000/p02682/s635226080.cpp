#include <bits/stdc++.h>

using namespace std;

int main() {
    int_fast64_t a, b, c, k;

    cin >> a >> b >> c >> k;

    if(k <= a) {
        printf("%ld\n", k);
    } else if(k <= a + b) {
        printf("%ld\n", a);
    } else {
        printf("%ld\n", 2 * a + b - k);
    }

    return 0;
}