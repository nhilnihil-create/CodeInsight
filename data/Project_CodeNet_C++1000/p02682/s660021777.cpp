#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(a >= k) {
        cout << k << endl;
        return 0;
    } else if(a + b >= k) {
        cout << a << endl;
        return 0;
    } else {
        cout << a - (k - a - b) << endl;
        return 0;
    }
}