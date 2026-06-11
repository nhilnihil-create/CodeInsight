#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int a, b, c;
int main() {
    DAU
    cin >> a >> b;
    c = (a + b) / 2;
    if (2 * c != a + b) {
        cout << "IMPOSSIBLE";
        PLEC
    }
    cout << c;
    PLEC
}
