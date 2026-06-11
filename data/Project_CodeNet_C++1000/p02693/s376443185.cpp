#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, cnt = 0, ans = 0;
    int a, b, k;
    cin >> k >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i % k == 0) {
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
    return 0;
}