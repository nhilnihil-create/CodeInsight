#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int x, y;
int main() {
    DAU
    cin >> x >> y;
    if (x < 1 || x > 9 || y < 1 || y > 9)
        cout << "-1";
    else cout << x * y;
    PLEC
}
