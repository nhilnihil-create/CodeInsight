#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    for (ll i=-1000; i<1001; i++) {
        for (ll j=-1000; j<1001; j++) {
            if (i*i*i*i*i - j*j*j*j*j == x) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
}
