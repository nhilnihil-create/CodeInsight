#include <iostream>

using namespace std;

typedef long long ll;


bool func(int n, ll k, ll *a, ll x) {
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += (a[i]+x-1)/x - 1;
    }

    return tmp <= k;
}

int main() {
    int n;  ll k;   cin >> n >> k;
    ll *a = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    ll l = 0, r = 1e9, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;

        if (func(n, k, a, mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;

    return 0;
}