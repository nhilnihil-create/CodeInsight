#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long a, b, k;
    cin >> a >> b >> k;

    a -= k;
    if (a < 0) {
        b += a;
        a = 0;
    }
    if (b < 0) b = 0;

    cout << a << ' ' << b << endl;
    return 0;
}
