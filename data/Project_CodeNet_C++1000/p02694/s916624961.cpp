#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll x; cin >> x;
    ll tmp = 100;
    ll year = 0;
    if (x <= tmp) cout << 0 << endl;
    while (tmp < x) {
        tmp += tmp / 100;
        year++;
    }
    cout << year << endl;
    return 0;
}