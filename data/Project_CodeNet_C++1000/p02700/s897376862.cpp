#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int i = 0;
    while (a > 0 && c > 0) {
        if ((i & 1) == 0) {
            c = c - b;
        } else {
            a = a - d;
        }
        i++;
    }
    if (a <= 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}
