#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int p, q;

    p = x;
    x = y;
    y = p;
    q = x;
    x = z;
    z = q;

    cout << x << " " << y << " " << z << endl;
}