#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int k;
    vector<int> a(3), b(3);
    bool f = false;
    cin >> a[0] >> a[1] >> a[2] >> k;
    rep(trit, pow(3, k)) {
        int tmp = trit;
        b = a;
        rep(i, k) {
            b[tmp % 3] *= 2;
            tmp /= 3;
        }
        if (b[0] < b[1] && b[1] < b[2]) {
            f = true;
            break;
        }
    }
    cout << ((f) ? "Yes" : "No") << endl;
    return 0;
}