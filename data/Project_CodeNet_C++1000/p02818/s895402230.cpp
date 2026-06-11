#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    if(a >= k) {
        a = a - k;
    } else {
        k = k - a;
        a = 0;
        if(b >= k) {
            b = b - k;
        } else {
            b = 0;
        }
    }

    cout << a << " " << b << endl;
    return 0;
}
