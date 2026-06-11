#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    ll x, a = 100, year = 0;
    cin >> x;
    while (a < x) {
        a += a / 100;
        year++;
    }
    cout << year << endl;
    return 0;
}