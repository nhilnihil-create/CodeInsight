#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, n;
    cin >> a >> b >> n;
    long long c;
    if (n < b) {
        c = (a*n)/b;
    } else {
        c = (a*(b-1))/b;
    }
    cout << c;
}
