#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll sN = sqrt(n) + 1;

    ll target = n;

    bool isNotFind = true;
    while (isNotFind) {
        bool isPrime = true;

        for (ll j = 2; j < sN; j++) {
            if (target % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            isNotFind = false;
        } else {
            target = target + 1;
        }
    }

    cout << target << endl;
}