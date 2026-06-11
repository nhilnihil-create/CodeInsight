#include <bits/stdc++.h>


using namespace std;
using ll = long long;

const int sz = 1e6 + 10;
int sp[sz];

int main() {
    ll n;
    cin >> n;
    ll res = 0;
    for(ll i = 1; i <= n; i++) {
        ll tmp = n / i;
        tmp = i * tmp * (tmp + 1) / 2;
        res += tmp;
    }
    cout << res << "\n";

}

