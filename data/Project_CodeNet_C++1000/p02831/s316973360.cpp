#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long max = a * b;
    long long res = 0;
    int tmp = (a < b ? b : a);
    for (long long i = tmp; i <= max; i += tmp) {
        if (i % a == 0 && i % b == 0) {
            res = i;
            break;
        }
    }

    cout << res << endl;

    return 0;
}
