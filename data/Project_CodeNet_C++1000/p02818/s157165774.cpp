#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
int64_t a,b,k;
    cin >> a >> b >> k;
    if (a >= k) {
        cout << a - k << ' ' << b;
    }
    else if (a < k && (k - a) <= b) {
        cout << 0 << ' ' << b - (k - a);
            }
    else if (a < k && (k - a) > b) {
    cout << 0 << ' ' << 0;
    }

}