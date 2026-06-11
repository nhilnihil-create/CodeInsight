#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
long long n, res;
int main() {
    DAU
    cin >> n;
    if (n & 1) {
        cout << 0;
        PLEC
    }
    n /= 2;
    while (n > 0)
        res += (n /= 5);
    cout << res;
    PLEC
}
