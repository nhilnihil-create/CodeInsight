#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll x, k, d;
    cin >> x >> k >> d;
    if (x > 0) {
        if (k < x / d) cout << x - k * d;
        else {
            k -= x / d;
            x %= d;
            if (k % 2) cout << d - x;
            else cout << x;
        }
    } else {
        if (k < -x / d) cout << -x - k * d;
        else {
            k -= -x / d;
            x %= d;
            if (k % 2) cout << x + d;
            else cout << -x;
        }
    }
}
