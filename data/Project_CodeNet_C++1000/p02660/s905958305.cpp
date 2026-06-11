#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll N;   cin >> N;

    ll ans = 0;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            ll tmp = 0;
            while (N % i == 0) {
                N /= i;
                tmp++;
            }

            ll k ;
            for (k = 1; (k+2)*(k+1)/2 <= tmp; k++) ;

            ans += k;
        }
    }

    if (N > 1)
        ans++;

    cout << ans << endl;

    return 0;
}