#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int k, x;
    cin >> k >> x;
    for (int i = k - 1; i > 0; --i) {
        cout << x - i << " ";
    }
    for (int i = 0; i < k; ++i) {
        if (i == k - 1) {
            cout << x + i << endl;
            return 0;
        }
        cout << x + i << " ";
    }
    return 0;
}