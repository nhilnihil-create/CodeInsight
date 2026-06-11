#include <iostream>

using namespace std;
using ll = long long;
ll MAX = 1e18;

ll a[100000];

int main() {
    int n;
    cin >> n;
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            cout << "0\n";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > MAX / res) {
            cout << "-1\n";
            return 0;
        }
        res *= a[i];
    }
    cout << res << '\n';
}