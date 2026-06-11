#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a ,b , k;
    cin >> a >> b >> k;

    if (k > a) {
        k -= a;
        a = 0;
        if (k > b) {
            b = 0;
        } else {
            b -= k;
        }
    } else {
        a = a - k;
    }

    cout << a << " " << b << endl;

    return 0;
}
