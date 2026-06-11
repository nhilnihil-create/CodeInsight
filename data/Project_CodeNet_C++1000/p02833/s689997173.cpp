#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long max = 10, z = 1;
    while (5*max < 1000000000000000000) {
        max *= 5;
        z++;
    }

    if (n % 2 == 0) {
        long long count = 0;
        while (z > 0) {
            if (n / max > 0) {
                count += z * (n / max - n / (max*5));
            }
            z--;
            max /= 5;
        }
        cout << count << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
