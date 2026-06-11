#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    int c = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < c) ans += c - a;
        if (a > c) c = a;
    }
    cout << ans << endl;
}