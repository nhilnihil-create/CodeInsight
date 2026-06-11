#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll tmp = 0;
    if ((B - A) % 2 == 0) {
        cout << B - (B + A) / 2 << endl;
    } else {
        ll left = A - 1;
        ll right = N - B;
        if (left > right) tmp = right + 1, right = N, left = A + tmp;
        else tmp = left + 1, left = 1, right = B - tmp;
        cout << right - (right + left) / 2 + tmp << endl;
    }
    return 0;
}
