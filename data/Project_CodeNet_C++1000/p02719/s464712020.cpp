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
    if (k - min < min) {
        min = k - min;
    }

    cout << min << endl;

    return 0;
}
