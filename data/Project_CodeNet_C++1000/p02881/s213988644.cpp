#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

bool isPrime(ll n) {
    Rep (i, 2, sqrt(n)+1) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll min = n - 1;
    if (!isPrime(n)) {
        Rep (i, 2, sqrt(n)+1) {
            if (n % i == 0) {
                ll j = n / i;
                ll k = (i-1) + (j-1);
                if (min > k) min = k;
            }
        }
    }
    cout << min << endl;
}