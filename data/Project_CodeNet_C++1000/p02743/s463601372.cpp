#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long double a, b, c;
    long double EPS = 1e-14;
    cin >> a >> b >> c;

    if (sqrtl(a) + sqrtl(b) < sqrtl(c)-EPS) cout << "Yes";
    else cout << "No";

    //
}
