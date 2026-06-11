#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    long long int a, b, c;
    cin >> a >> b >> c;

    if (a + b + 2 * sqrtl(a * b) < c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
