#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int LGA = 60;

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll a[n];
    ll f = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] &= ~f;
    }

    ll bs[LGA] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = LGA - 1; j >= 0; j--) {
            if (a[i] >> j & 1) {
                a[i] ^= bs[j];
            }
        }

        for (int j = LGA - 1; j >= 0; j--) {
            if (a[i] >> j & 1) {
                bs[j] = a[i];
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = LGA - 1; i >= 0; i--) {
        if ((ans ^ bs[i]) > ans) {
            ans ^= bs[i];
        }
    }
    ans = ans * 2 + f;

    cout << ans << endl;

    return 0;
}
