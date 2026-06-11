#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;
using namespace std;
long double a, b, c;
int main() {
    DAU
    cin >> a >> b >> c;
    if (a + b + 2.0 * sqrt(a * b) < c)
        cout << "Yes";
    else cout << "No";
    PLEC
}
