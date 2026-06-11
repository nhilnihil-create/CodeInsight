#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, k, s;
    cin >> n >> k >> s;

    rep(i, n) {
        if (i < k)
            cout << s;
        else {
            if (s == 1e9)
                cout << 1;
            else
                cout << s + 1;
        }
        if (i != n - 1) cout << ' ';
    }
    cout << endl;

    return 0;
}
