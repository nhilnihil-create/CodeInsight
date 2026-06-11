#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    if (x == 1) return 1;
    return 2 * f(floor(x / 2)) + 1;
}

int main(void) {
    long long h;
    cin >> h;
    cout << f(h) << endl;
    return 0;
}