#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll t = sqrt(n);

    for (ll i = t; i >= 0; i--) {
        if (n % i == 0) {
            cout << i-1+(n/i)-1 << endl;
            return 0;
        }

    }
    return 0;
}