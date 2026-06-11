#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n;   cin >> n;
    ll *d = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> d[i];


    if (d[0] != 0) {
        cout << 0 << endl;
        return 0;
    }

    
    sort(d, d+n);

    ll *cnt = new ll[n];
    for (int i = 0; i < n; i++)
        cnt[i] = 0;
    for (ll i = 0; i < n; i++) {
        cnt[d[i]]++;
    }
    
    for (ll i = 0; i < n-1; i++) {
        if (d[i] + 1 < d[i+1]) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll i = 0, c = 0;
    while (i < n && cnt[i++])
        c++;

    if (cnt[0] != 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;

    for (int i = 0; i < c-1; i++) {
        if (cnt[i] > 0) {
            for (int j = 0; j < cnt[i+1]; j++) {
                ans *= cnt[i];
                ans %= 998244353;
            }
        }
    }

    cout << ans << endl;
    return 0;
}