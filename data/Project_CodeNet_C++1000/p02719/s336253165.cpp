#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long min;
    if (n % k == 0) {
        cout << 0 << endl;
        return 0;
    }
    min = n % k;
    if ((min - k) * -1 < min) {
        min = (min - k) * -1;
    }

    cout << min << endl;

    return 0;
}
